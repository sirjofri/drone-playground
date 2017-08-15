#ifndef sensor_h
#define sensor_h
#include "../attach/attach.h"
#include "../world.h"

template<typename T>
class Sensor : public Attach
{
	public:
		using Attach::Attach;

		/** Constructor of a Sensor
		 *
		 * @param mass Mass of the sensor module
		 **/
		Sensor<T>(double mass);

		/** get the value of the sensor
		 *
		 * @return type specified by template
		 **/
		virtual T get_value();

		/** set the world as data source
		 *
		 * @param world the world
		 **/
		void set_world(World* world);

	protected:
		World* _world;
		T value;
};

// vim:ts=4:sw=4:noet:
#endif
