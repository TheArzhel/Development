#ifndef  _VECTOR3_H_
#define  _VECTOR3_H_
 
#include <math.h>

template <class T>



class vec {
private:
	T x, y, z;
public:

	//constructor
	vec() : x(0), y(0), z(0) {}

	//falta uno

	vec(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}

	//desturctor

	~vec() {}

	//operators

	vec operator+ (const vec &vector) {
		vec sumvec;
		sumvec.x = x + vector.x;
		sumvec.y = y + vector.y;
		sumvec.z = z + vector.z;
		return sumvec;
	}

	vec operator- (const vec &vector) {
		vec resvec;
		resvec.x = x - vector.x;
		resvec.y = y - vector.y;
		resvec.z = z - vector.z;
		return resvec;
	}

	void operator+= (const vec &vector) {
		x += vector.x;
		y += vector.y;
		z += vector.z;
	}

	void operator-= (const vec &vector) {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;

	}

	bool operator== (const vec &vector) const {
		if (x == vector.x && y == vector.y && z == vector.z) {
			return true;
		}
		else {
			return false;
		}

	}



	void operator= (const vec &vector) {
		x = vector.x;
		y = vector.y;
		z = vector.z;
	}



	//

	vec normalize() {
		vec normievec;
		T length;
		length = sqrt((x*x) + (y*y) + (z*z));
		normievec.x = x / length;
		normievec.y = y / length;
		normievec.z = z / length;
		return normievec;
	}


	bool is_zero( const vec vector) const 
	{
		if (vector.x == 0 && vector.y == 0 && vector.z == 0)
			return true;
		else
			return false;
	}

	void zero(vec &vector) { vector.x = vector.y = vector.z = 0; }

	void distance_to( const vec &vector) const
	{
		T a, b, c;
		a = x - vector.x;
		b = y - vector.y;
		c = z - vector.z;
		cout << "the distances from each component of each vector are " << "x: " << a << " y: " << b << " z:  " << c << endl;

	}

	void print() const {

		cout << "x: " << x << " y: " << y << " z: " << z << endl;
	}
};








#endif // ! _VECTOR3_H_

