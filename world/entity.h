#ifndef entity_h
#define entity_h
#include "../misc/vect3d.h"

/** a general entity. spawnable and it has a position
 **/
class Entity
{
	public:
		/** get the position of the entity
		 *
		 * @return position of the entity
		 **/
		const vect3d* get_position() { return position; };

		/** get the direction of the entity
		 *
		 * @return direction of the entity
		 **/
		const vect3d* get_direction() { return movement; }

		/** move the entity around
		 *
		 * @param a direction, normalized with time
		 * @param time the passed time
		 **/
		void move(const vect3d a, double time) // physical movement
		{
			if( !is_static )
			{
				vect3d own_movement = *movement * time;
				own_movement += a;
				*position += own_movement;
				*movement += a;
			}
		};

		/** initialize the entity (or: move the object around, like warp)
		 *
		 * @param location the location where the object should be placed
		 * @param direction acceleration direction
		 **/
		void initialize(vect3d* location, vect3d* direction) { position = location; movement = direction; };

	private:
		bool is_static = false;
		vect3d* position;
		vect3d* movement;
};

// vim:ts=4:sw=4:noet:
#endif
