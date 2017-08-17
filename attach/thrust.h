#ifndef thrust_h
#define thrust_h
#include "attach.h"

/** general thrust (or engine).
 **/
class Thrust : public Attach
{
	public:
		using Attach::Attach;
		/** basic constructor
		 *
		 * @param min minimum value (mostly 0)
		 * @param max maximum value (the higher the more power)
		 **/
		Thrust(double min, double max);
};

// vim:ts=4:sw=4:noet
#endif
