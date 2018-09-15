#include <stdio.h>
#include <math.h>
class vec {
private:
	int x, y, z;
public:

	//constructor
	vec() : x(0), y(0), z(0) {}

	vec(int xx) : x(xx), y(0), z(0) {}
	vec(int yy) : x(0), y(yy), z(0) {}
	vec(int zz) : x(00), y(0), z(zz) {}

	vec(int xx, int yy, int zz) : x(xx), y(yy), z(zz) {}

	//desturctor

	~vec() {}

	//operators

	vec operator+ (vec &vector) {
		vec sumvec;
		sumvec.x = x + vector.x;
		sumvec.y = y + vector.y;
		sumvec.z = z + vector.z;
		return sumvec;
	}

	vec operator- (vec &vector) {
		vec resvec;
		resvec.x = x - vector.x;
		resvec.y = y - vector.y;
		resvec.z = z - vector.z;
		return resvec;
	}

	vec& operator+= (vec &vector) {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}

	vec& operator-= (vec &vector) {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}

	bool operator== (vec &vector) {
		if (x == vector.x && y == vector.y && z == vector.z) {
			return true;
		}
		else {
			return false;
		}

	}

	vec operator= (vec &vector) {
		vec newvec;
		newvec.x = vector.x;
		newvec.y = vector.y;
		newvec.z = vector.z;
		return newvec;


	}
	//methods
	vec normalize() {
		vec normievec;
		int length;
		length = sqrt((x*x) + (y*y) + (z*z));
		normievec.x = x / length;
		normievec.y = y / length;
		normievec.z = z / length;
		return normievec;
	}


	bool is_zero(vec vector)
	{
		if (vector.x == 0 && vector.y == 0 && vector.z == 0)
			return true;
		else
			return false;
	}

	void zero( vec &vector) { vector.x = vector.y = vector.z = 0; }

	//distance to
};

int main() {


	return 0;
}