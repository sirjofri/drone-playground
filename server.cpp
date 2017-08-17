#include "server.h"

/** should the server loop run? */
bool s_loop_running = false;

/** the prompt of the command line interface */
const std::string PROMPT = "\n-> ";

/** the server loop. this should be started in a new thread */
void s_loop()
{
	World* w = new World(10, 10, 10, 9.81);
	Drone* d = new Drone(10, 20, 30, -2, 2);

	setup_world(w, d);

	clock_t start = clock(), round;
	clock_t cps = CLOCKS_PER_SEC;
	while(s_loop_running)
	{
		round = clock();
		clock_t diff = round - start;
		std::cout << diff << "\t";
		w->tick(double(diff)/CLOCKS_PER_SEC);
		print_pos(d);
		std::cout << cps << "\t" << d->get_direction()->z << std::endl;
		start = round;
		cps = CLOCKS_PER_SEC;
	}
}

/** the cli loop. It asks for commands and executes them
 **/
void c_loop()
{
	std::string command;
	std::thread* mainloop;

	do
	{
		std::cout<< PROMPT <<std::flush;
		std::getline(std::cin, command);
		switch(cmd(command))
		{
			case CMDS_RUN:
				std::cout<<"RUN command";
				s_loop_running = true;
				mainloop = new std::thread(s_loop);
				break;
			case CMDS_EXIT:
				s_loop_running = false;
				break;
			case CMDS_EMPTY:
				break;
			case CMDS_INVALID:
			default:
				std::cout<<"Command not found";
		}
	} while (command != CMD_EXIT);
	if(mainloop != nullptr)
	{
		mainloop->join();
		std::cout<<"Server loop quit"<<std::endl;
	}
}

int main()
{
	c_loop();
}

// vim:ts=4:sw=4:noet
