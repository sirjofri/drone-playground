#ifndef attach_h
#define attach_h

/** general attachment. it attaches to the drone surface.
 **/
class Attach
{
	public:
		/** constructor of attach modules
		 *
		 * @param mass the mass of the module
		 * @param min the minimum of the range
		 * @param max the maximum of the range
		 * @param initial the neutral value of the range
		 **/
		Attach(double mass,
		       double min,
		       double max,
		       double initial);
		
		/** get the mass of the module
		 *
		 * @return mass of the module
		 **/
		const double get_mass();

		/** get the minimum of the range
		 *
		 * @return minimum of the range
		 **/
		const double get_min();

		/** get the maximum of the range
		 *
		 * @return maximum of the range
		 **/
		const double get_max();

		/** get the current value
		 *
		 * @return current value
		 **/
		double get_current();

	private:
		const double mass;
		const double min;
		const double max;
		double current;
	protected:
};

// vim:ts=4:sw=4:noet:
#endif
