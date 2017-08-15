#ifndef rudder_h
#define rudder_h
#include "attach.h"

class Rudder : public Attach
{
	public:
		using Attach::Attach;
		Rudder(double min_pos, double max_pos);
};

// vim:ts=4:sw=4:noet:
#endif
