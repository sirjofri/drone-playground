#ifndef SENSOR_CPP
#define SENSOR_CPP
#include "sensor.h"

template<typename T>
Sensor<T>::Sensor(double mass)
 : Attach(mass, 0, 0, 0)
{
	this->value = T(42);
}

template<typename T>
void Sensor<T>::set_world(World* world)
{
	this->_world = world;
}

template<typename T>
T Sensor<T>::get_value()
{
	return value;
}

// vim:ts=4:sw=4:noet:
#endif
