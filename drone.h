#ifndef drone_h
#define drone_h
#include "world/entity.h"
#include "attach/attach.h"
#include "attach/thrust.h"
#include "attach/rudder.h"
#include "sensors/sensor.cpp"
#include "misc/vect3d.h"

class Drone : public Entity
{
	public:
		/** drone constructor
		 *
		 * @param _mass mass of the frame
		 * @param thrust_lr maximum of left/right thrusters
		 * @param thrust_forward maximum of main thrust
		 * @param rudder_min minimum of rudder
		 * @param rudder_max maximum of rudder
		 **/
		Drone(double _mass,
		      double thrust_lr,
		      double thrust_forward,
			  double rudder_min,
			  double rudder_max);

		/** get pitch
		 *
		 * @return pitch
		 **/
		double get_pitch();

		/** get yaw
		 *
		 * @return yaw
		 **/
		double get_yaw();

		/** get roll
		 *
		 * @return roll
		 **/
		double get_roll();

		// getter for attachments
		Attach* const get_thrust_r();
		Attach* const get_thrust_l();
		Attach* const get_thrust_f();
		Attach* const get_rudder_pitch();

		/** get mass of the whole drone
		 *
		 * @return mass of the drone
		 **/
		const double get_mass();

		/** get sensor object
		 *
		 * @return sensor component
		 **/
		Sensor<double>* const get_s_altitude();

	private:
		const double mass;
		double pitch;
		double yaw;
		double roll;
		Attach* const thrust_left;
		Attach* const thrust_right;
		Attach* const thrust_forward;
		Attach* const r_pitch;
		Sensor<double>* const altitude;
};

// vim:ts=4:sw=4:noet:
#else
#endif
