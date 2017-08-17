#ifndef vect3d_h
#define vect3d_h

/** my vector struct
 **/
struct vect3d
{
	double x;
	double y;
	double z;

	/** create a vector with values
	 * 
	 * @param x_val x value
	 * @param y_val y value
	 * @param z_val z value
	 **/
	vect3d(double x_val, double y_val, double z_val)
	 : x(x_val), y(y_val), z(z_val)
	{ }

	/** create an empty vector with 0 0 0
	 **/
	vect3d() : x(0), y(0), z(0)
	{ }

	/** adds vectors together
	 **/
	vect3d operator+=(const vect3d &a)
	{
		this->x += a.x;
		this->y += a.y;
		this->z += a.z;
		return *this;
	}

	/** multiplies vector with a double value
	 **/
	vect3d operator*(const double &a)
	{
		vect3d* result = new vect3d(this->x * a, this->y * a, this->z * a);
		return *result;
	}
};

// vim:ts=4:sw=4:noet
#endif
