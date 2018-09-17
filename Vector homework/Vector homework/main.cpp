#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

class vec {
private:
	int x, y, z;
public:

	//constructor
	vec() : x(0), y(0), z(0) {}

	//falta uno

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

	void operator+= (vec &vector) {
		x += vector.x;
		y += vector.y;
		z += vector.z;
	}

	void operator-= (vec &vector) {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		
	}

	bool operator== (vec &vector) {
		if (x == vector.x && y == vector.y && z == vector.z) {
			return true;
		}
		else {
			return false;
		}

	}

	

	void operator= ( const vec &vector) {
		x = vector.x;
		y = vector.y;
		z = vector.z; 
	}

	

	//

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

	void print() {
	
		cout << "x: " << x << " y: " << y << " z: " << z << endl;
	}
};

int main() {

	cout << "vectors" << endl;

	vec vector1 (1, 1, 1);
	vec vector2 (2, 0, 2);
	vec vector3;
	vec vector4;
	vec vector5;

	cout << "vecto 1:" << endl;
	vector1.print();
	cout << "vecto 2:" << endl;
	vector2.print();
	cout << "vecto 3:" << endl;
	vector3.print();
	cout << endl; //0,0,0
	
	vector3 = (vector1 + vector2);
	vector3.print();
	cout << endl; //3,1,3

	vector3 = (vector1 - vector2);
	vector3.print();
	cout << endl; //-1.1.-1

	cout << "vecto 4:" << endl;
	vector4 += vector1;
	vector4.print();
	cout << endl; //1.1.1

	vector4 -= vector1;
	vector4.print();
	cout << endl << endl; //0,0,0

	cout << (vector4 == vector3) << endl;
	cout << (vector4 == vector5) << endl;


system("pause");
	return 0;
}