#include "world.h"

World::World(int size_x,
             int size_y,
             int size_z,
             double gravity)
 : _size_x(size_x),
   _size_y(size_y),
   _size_z(size_z)
{
	_gravity = new vect3d(0, 0, -gravity);
}

int World::spawn_entity(Entity* e, int x, int y, int z)
{
	entity = e;
	vect3d* init_pos = new vect3d(x, y, z);
	vect3d* init_dir = new vect3d(0, 0, 0);
	e->initialize(init_pos, init_dir);
	return 0;
}

void World::tick(double time)
{
	vect3d distance = *_gravity * time;
	entity->move((const vect3d)distance, time);
}

// vim:ts=4:sw=4:noet
