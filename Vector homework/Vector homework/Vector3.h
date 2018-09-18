#ifndef  _VECTOR3_H_
#define  _VECTOR3_H_
#include <math.h>

template <class T>

class vec 
{
private:
	T x, y, z;
public:

	//constructor
	vec() {}

	vec(const vec& vector) : x(vector.x), y(vector.y), z(vector.z) {}

	vec(T x, T y, T z) : x(x), y(y), z(z) {}

	//desturctor

	~vec() {}

	//operators

	vec operator+ (const vec &vector) const
	{
		return vec ((x + vector.x), (y + vector.y), (z + vector.z));
		
	}

	vec operator- (const vec &vector) const
	{
		return vec (x - vector.x, y - vector.y, z - vector.z);
	}

	vec operator+= (const vec &vector) 
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}

	vec operator-= (const vec &vector) 
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}

	bool operator== (const vec &vector) const 
	{
		return (x == vector.x && y == vector.y && z == vector.z); 
	}

	vec operator= (  vec &vector) 
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
		return *this;
	}

	//methods

	vec normalize() 
	{
		T length = sqrt((x*x) + (y*y) + (z*z));
		return vec (x / length, y / length, z / length);
	}


	bool is_zero( const vec vector) const 
	{
		return (vector.x == 0 && vector.y == 0 && vector.z == 0);
	}

	void zero(vec &vector) 
	{ 
		vector.x = vector.y = vector.z = 0; 
	}

	void distance_to( const vec &vector) const
	{
		T a, b, c;
		a = x - vector.x;
		b = y - vector.y;
		c = z - vector.z;
		cout << "the distances from each component of each vector are " << "x: " << a << " y: " << b << " z:  " << c << endl;
	}

	void print() const 
	{
		cout << "x: " << x << " y: " << y << " z: " << z << endl;
	}
};


#endif // ! _VECTOR3_H_

