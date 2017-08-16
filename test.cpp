#include <iostream>
#include <time.h>
#include "world/world.h"
#include "world/drone.h"
#include <sys/socket.h>

void print_pos(Drone* d)
{
	std::cout<<" - Position: "<<d->get_position()->x << " "
	                          <<d->get_position()->y << " "
	                          <<d->get_position()->z << std::endl;
}

void setup_world(World* w)
{
	std::cout<<"World is set up"<<std::endl;
}

void spawn_drone(Drone* d, World* w)
{
	w->spawn_entity(d, 5, 5, 5);
	std::cout<<"Entity is spawned"<<std::endl;
	print_pos(d);
}

int main()
{
	World* w = new World(10, 10, 10, 9.81);
	Drone* d = new Drone(10, 20, 30, -2, 2);

	setup_world(w);
	spawn_drone(d, w);

	int number_of_ticks = 20;
	clock_t start, round;
	start = clock();
	while(number_of_ticks > 0)
	{
		round = clock();
		clock_t diff = round - start;
		w->tick(double(diff)/CLOCKS_PER_SEC);
		print_pos(d);
		number_of_ticks--;
	}

	/*
	w->tick(0.1);
	print_pos(d);
	w->tick(0.1);
	print_pos(d);
	w->tick(0.1);
	print_pos(d);
	*/

	/*
	// parameters: mass, help_max, main_max, rudder_min, rudder_max
	Drone* mydrone = new Drone(10, 20, 30, -2, 2);
	std::cout << "Roll: " << mydrone->get_roll() << " "
	          << "Yaw: " << mydrone->get_yaw() << " "
		      << "Pitch: " << mydrone->get_pitch() << " "
		      << std::endl;
	std::cout << "Thrust Right:\n" // Right Thrust
	          << "  Max Thrust: " << mydrone->get_thrust_r()->get_max() << std::endl;
	std::cout << "Thrust Left:\n" // Left Thrust
	          << "  Min Thrust: " << mydrone->get_thrust_l()->get_min() << std::endl;
	std::cout << "Thrust Forward:\n" // Main Thrust
	          << "  Current Thrust: " << mydrone->get_thrust_f()->get_current() << std::endl;
	std::cout << "Rudder Pitch:\n" // Rudder
	          << "  Position: " << mydrone->get_rudder_pitch()->get_current() << std::endl;
	std::cout << "Mass:\n" // Masses
	          << "  Thrust L/R: 2x " << mydrone->get_thrust_r()->get_mass() << "\n"
			  << "  Thrust Main: " << mydrone->get_thrust_f()->get_mass() << "\n"
			  << "  Rudder: " << mydrone->get_rudder_pitch()->get_mass() << "\n"
	          << "  Sum: " << mydrone->get_mass() << std::endl;
	std::cout << "Sensors:\n" // Sensors
	          << "  Altitude: " << mydrone->get_s_altitude()->get_value() << std::endl;
	*/

	exit(0);
}

// vim:ts=4:sw=4:noet:
