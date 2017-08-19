#ifndef sensor_h
#define sensor_h
#include "attach.h"
#include "world.h"

/** basic sensor class. it connects to the world to get some values.
 **/
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
		/** pointer to the world. This is used to get some sensor-
		 * specific information.
		 **/
		World* _world;
		/** the value of the sensor. can be used to store the wanted
		 * value. You can maybe fake some delay.
		 **/
		T value;
};

#include "sensor.cpp"

// vim:ts=4:sw=4:noet:
#endif
