#ifndef world_h
#define world_h
#include "entity.h"
#include "../misc/vect3d.h"

/** The world (or environment...
 *
 **/
class World
{
	public:
		/** Constructor for a World
		 *
		 * @param size_x Size in x direction
		 * @param size_y Size in y direction
		 * @param size_z Size in z direction
		 * @param gravity Gravity in this World
		 **/
		World(int size_x, int size_y, int size_z, double gravity);

		/** spawn a entity into the world
		 *
		 * @param e Entity to spawn
		 * @param x x position
		 * @param y y position
		 * @param z z position
		 * @return error code (0 = everything is ok)
		 **/
		int spawn_entity(Entity* e, int x, int y, int z);

		/** basic tick function
		 *
		 * @param time number of seconds
		 **/
		void tick(double time);

	private:
		const int _size_x;
		const int _size_y;
		const int _size_z;
		vect3d* _gravity;
		Entity* entity; // TODO: vector/array
};

// vim:ts=4:sw=4:noet:
#endif
