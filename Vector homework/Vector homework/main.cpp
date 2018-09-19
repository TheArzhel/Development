#include "Vector3.h"

#include <stdio.h>
#include <math.h>
#include <iostream>


using namespace std;



int main() {

	cout << "vectors" << endl;

	vec<int> vector1 (1, 1, 1);
	vec<int> vector2 (2, 0, 2);
	vec<int> vector3=vector3.zero;
	vec<int> vector4=vector4.zero;
	vec<int> vector5=vector5.zero;

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