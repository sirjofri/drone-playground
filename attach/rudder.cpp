#include "rudder.h"

Rudder::Rudder(double min_pos, double max_pos)
 : Attach(5, min_pos, max_pos, 0.2)
{ }

// vim:ts=4:sw=4:noet:
