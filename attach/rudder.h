#ifndef rudder_h
#define rudder_h
#include "attach.h"

/** general rudder
 **/
class Rudder : public Attach
{
	public:
		using Attach::Attach;
		/** rudder constructor
		 *
		 * @param min_pos minimum position of the rudder
		 * @param max_pos maximum position of the rudder
		 **/
		Rudder(double min_pos, double max_pos);
};

// vim:ts=4:sw=4:noet:
#endif
