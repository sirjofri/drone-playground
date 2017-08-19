#ifndef server_h
#define server_h
#include <iostream>
#include <time.h>
#include "world.h"
#include "drone.h"
#include <sys/socket.h>
#include <thread>
#include <string>
#include "commands.h"

/** print the position of the drone
 *
 * @param d drone
 **/
void print_pos(Drone* d)
{
	std::cout<<" - Position: "
	         << d->get_position()->x << " "
	         << d->get_position()->y << " "
	         << d->get_position()->z
	         << std::endl;
}

/** sets up the world, spawns the drone
 *
 * @param w world
 * @param d drone
 **/
void setup_world(World* w, Drone* d)
{
	w->spawn_entity(d, 5, 5, 5);
	std::cout<<"Entity is spawned"<<std::flush;
}

// vim:ts=4:sw=4:noet
#endif
