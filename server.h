#ifndef server_h
#define server_h

void print_pos(Drone* d)
{
	std::cout<<" - Position: "
	         << d->get_position()->x << " "
	         << d->get_position()->y << " "
	         << d->get_position()->z
	         << std::endl;
}

void setup_world(World* w, Drone* d)
{
	w->spawn_entity(d, 5, 5, 5);
	std::cout<<"Entity is spawned"<<std::endl;
}

// vim:ts=4:sw=4:noet
#endif
