#ifndef vect3d_h
#define vect3d_h

struct vect3d
{
	double x;
	double y;
	double z;

	vect3d(double x_val, double y_val, double z_val)
	 : x(x_val), y(y_val), z(z_val)
	{ }

	vect3d() : x(0), y(0), z(0)
	{ }

	vect3d operator+=(const vect3d &a)
	{
		this->x += a.x;
		this->y += a.y;
		this->z += a.z;
		return *this;
	}

	vect3d operator*(const double &a)
	{
		vect3d* result = new vect3d(this->x * a, this->y * a, this->z * a);
		return *result;
	}
};

// vim:ts=4:sw=4:noet
#endif
