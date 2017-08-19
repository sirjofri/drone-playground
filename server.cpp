#include "server.h"

/** global world */
World* w;
/** global drone */
Drone* d;

// some socket specific variables
int sockfd, newsockfd, portno; // server socket, client socket, port number
socklen_t clilen; // length of cli_addr
char buffer[256]; // read/write buffer
struct sockaddr_in serv_addr, cli_addr; // server and client address
int sock_read; // socket has read some stuff
bool sock_running = false; // socket is running
// end of socket variables

void sock_loop()
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		std::cout<<"Error opening socket"<<std::endl;
		return;
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if(bind(sockfd, (struct  sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		std::cout<<"Error on binding"<<std::endl;
		return;
	}
	listen(sockfd, 5);
	clilen = sizeof(cli_addr);
	while(sock_running)
	{
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if(newsockfd < 0)
		{
			std::cout<<"Error on accept"<<std::endl;
			return;
		}
		bzero(buffer, 256);
		sock_read = read(newsockfd, buffer, 255);
		if(sock_read < 0)
		{
			std::cout<<"Error on reading from socket"<<std::endl;
			return;
		}
		std::cout<<"Message: "<<buffer<<std::endl;
		sock_read = write(newsockfd, "Received", 8);
		close(newsockfd);
	}
	close(sockfd);
}

/** should the server loop run? */
bool s_loop_running = false;

/** the prompt of the command line interface */
const std::string PROMPT = "-> ";

/** Help text */
const std::string HELP_TEXT = "valid commands are:\n exit\thelp\trun";

/** the server loop. this should be started in a new thread */
void s_loop()
{
	w = new World(10, 10, 10, 9.81);
	d = new Drone(10, 20, 30, -2, 2);

	setup_world(w, d);

	clock_t start = clock(), round;
	while(s_loop_running)
	{
		round = clock();
		clock_t diff = round - start;
		w->tick(double(diff)/CLOCKS_PER_SEC);
		start = round;
	}
}

/** the cli loop. It asks for commands and executes them
 **/
void c_loop()
{
	std::string command;
	std::thread* mainloop = nullptr;
	std::thread* sockloop = nullptr;

	do
	{
		std::cout<< PROMPT <<std::flush;
		std::getline(std::cin, command);
		switch(cmd(command))
		{
			case CMDS_EXIT:
				s_loop_running = false;
				sock_running = false;
				break;
			case CMDS_HELP:
				std::cout<<HELP_TEXT<<std::flush;
				break;
			case CMDS_SOCK:
				if(sockloop == nullptr) // prevent server socket from running twice!
				{
					bool trying = true;
					do {
						std::cout<<"Enter server port: "<<std::flush;
						std::cin>>portno;
						if(std::cin.fail() || portno < 2000 || portno >= 25565)
						{
							std::cin.clear();
							std::cin.ignore();
							std::cout<<"Incorrect input. Try again!"<<std::endl;
						} else {
							trying = false;
						}
					} while(trying);
					sock_running = true;
					sockloop = new std::thread(sock_loop);
				} else {
					std::cout<<"Socket loop is already running!";
				}
				break;
			case CMDS_RUN:
				if(mainloop == nullptr) // prevent loop from running twice!
				{
					s_loop_running = true;
					mainloop = new std::thread(s_loop);
				} else {
					std::cout<<"Server loop is already running!";
				}
				break;
			case CMDS_EMPTY:
				break;
			case CMDS_INVALID:
			default:
				std::cout<<"Command not found";
		}
		if(cmd(command) != CMDS_EMPTY)
		{
			std::cout<<std::endl;
		}
	} while (command != CMD_EXIT);
	if(mainloop != nullptr)
	{
		mainloop->join();
		std::cout<<"Server loop quit"<<std::endl;
	}
	if(sockloop != nullptr)
	{
		shutdown(sockfd, SHUT_RDWR);
		sockloop->join();
		std::cout<<"Socket loop quit"<<std::endl;
	}
}

int main()
{
	c_loop();
}

// vim:ts=4:sw=4:noet
