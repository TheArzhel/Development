 #include <iostream>
#include <stdio.h>
#include "String.h"

using namespace std;

int main()
{

	String saludo("hola");
	String saludo2("ola k ase");
	String saludo_copia(saludo);
	String vacio("");

	if (saludo.empty()) {
		cout << "esta vacio " << endl;
	}
	else {
		cout << "esta lleno " << endl;
	}

	
	cout << saludo2.pointer() << endl;
	cout <<"size is "<< saludo2.size()<< "chars" << endl;


	saludo2.clear();
	cout << "size is " << saludo2.size() << "chars" << endl;


	bool seraigual = (saludo == saludo_copia);
	cout << seraigual << endl;

	
	saludo2 = saludo;
	cout << saludo2.pointer() << endl;

	
	saludo_copia += saludo;
	cout << saludo_copia.pointer() << endl;

	cout << endl << endl;

	cout << saludo.pointer() << endl;
	cout << saludo2.pointer() << endl;
	cout << saludo_copia.pointer() << endl;

	saludo= saludo + saludo2;

	cout << saludo.pointer() << endl;
	cout << saludo2.pointer() << endl;
	cout << saludo_copia.pointer() << endl;
	cout << endl;

	bool seraigual2 = (saludo != saludo_copia);
	cout << seraigual2 << endl;

	




	system("pause");
	return 0;
}
