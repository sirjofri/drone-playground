#include "attach.h"

Attach::Attach(double _mass,
               double _min,
               double _max,
               double initial)
 : mass(_mass),
   min(_min),
   max(_max),
   current(initial)
{

}

const double Attach::get_mass()
{
	return mass;
}

const double Attach::get_min()
{
	return min;
}

const double Attach::get_max()
{
	return max;
}

double Attach::get_current()
{
	return current;
}

// vim:ts=4:sw=4:noet:
