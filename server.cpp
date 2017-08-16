#include <iostream>
#include <time.h>
#include "world/world.h"
#include "world/drone.h"
#include <sys/socket.h>
#include "server.h"

int main()
{
	World* w = new World(10, 10, 10, 9.81);
	Drone* d = new Drone(10, 20, 30, -2, 2);

	setup_world(w, d);

	int number_of_ticks = 0;
	clock_t start = clock(), round;
	clock_t cps = CLOCKS_PER_SEC;
	while(number_of_ticks < 900)
	{
		round = clock();
		clock_t diff = round - start;
		std::cout << diff << "\t";
		w->tick(double(diff)/CLOCKS_PER_SEC);
		print_pos(d);
		std::cout << cps << "\t" << d->get_direction()->z << std::endl;
		start = round;
		cps = CLOCKS_PER_SEC;
		number_of_ticks++;
	}
}

// vim:ts=4:sw=4:noet
