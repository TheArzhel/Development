#ifndef  _VECTOR3_H_
#define  _VECTOR3_H_
#include <math.h>

template <class Type>

class vec 
{
private:
	Type x, y, z;
public:

	//constructor
	vec() {}

	vec(const vec& vector) : x(vector.x), y(vector.y), z(vector.z) {}

	vec(Type x, Type y, Type z) : x(x), y(y), z(z) {}

	//destructor

	/*virtual*/ ~vec() {}

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

	vec operator= ( const vec &vector) 
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
		return *this;
	}

	//methods

	vec as_normalize() const
	{
		Type length = sqrt((x*x) + (y*y) + (z*z));
		return vec (x / length, y / length, z / length);
	}

	vec normalize() 
	{
		Type length = sqrt((x*x) + (y*y) + (z*z));
		x = x / length;
		y = y / length;
		z = z / length; 
		return *this;
	}

	bool is_zero() const 
	{
		return (x == 0Type && y == 0 && z == 0);
	}

	vec zero() 
	{ 
		vector.x = vector.y = vector.z = 0; 
		return *this;
	}

	void distance_to( const vec &vector) const //change 
	{
		Type a = x - vector.x;
		Type b = y - vector.y;
		Type c = z - vector.z;
		// eliminar 
		cout << "the distances from each component of each vector are " << "x: " << a << " y: " << b << " z:  " << c << endl;
	}

	void print() const 
	{
		cout << "x: " << x << " y: " << y << " z: " << z << endl;
	}
};


#endif // ! _VECTOR3_H_

