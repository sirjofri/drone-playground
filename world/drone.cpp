#include "drone.h"

Drone::Drone(double _mass,
             double thrust_lr,
             double thrust_forward,
             double rudder_min,
             double rudder_max)
 : mass(_mass),
   thrust_left(new Thrust(0, thrust_lr)),
   thrust_right(new Thrust(0, thrust_lr)),
   thrust_forward(new Thrust(0, thrust_forward)),
   r_pitch(new Rudder(rudder_min, rudder_max)),
   altitude(new Sensor<double>(1))
{
	this->pitch = 0;
	this->yaw = 0;
	this->roll = 0;
}

double Drone::get_pitch()
{
	return this->pitch;
}

double Drone::get_yaw()
{
	return this->yaw;
}

double Drone::get_roll()
{
	return this->roll;
}

Attach* const Drone::get_thrust_r()
{
	return this->thrust_right;
}

Attach* const Drone::get_thrust_l()
{
	return this->thrust_left;
}

Attach* const Drone::get_thrust_f()
{
	return this->thrust_forward;
}

Attach* const Drone::get_rudder_pitch()
{
	return this->r_pitch;
}

Sensor<double>* const Drone::get_s_altitude()
{
	return altitude;
}

const double Drone::get_mass()
{
	const double sum = thrust_left->get_mass()
	                 + thrust_right->get_mass()
	                 + thrust_forward->get_mass()
	                 + r_pitch->get_mass()
	                 + altitude->get_mass()
	                 + mass;
	return sum;
}

// vim:ts=4:sw=4:noet
