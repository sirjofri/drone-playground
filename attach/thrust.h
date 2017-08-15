#ifndef thrust_h
#define thrust_h
#include "attach.h"

class Thrust : public Attach
{
	public:
		using Attach::Attach;
		Thrust(double min, double max);
};

// vim:ts=4:sw=4:noet
#endif
