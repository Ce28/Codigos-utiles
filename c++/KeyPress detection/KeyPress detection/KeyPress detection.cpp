// KeyPress detection.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <iostream>
#include <conio.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char key;
	int asciiValue;
	cout << "Presione una tecla para saber su codigo ascii\nPrecione ESC para salir\n" << endl;
	while (1)
	{
		key = _getch();
		asciiValue = key;
		if (asciiValue == 27)
			break;
		cout << "Tecla presionada-> \" " << key << " \" valor ascii = " << asciiValue << endl;
	}

	return 0;
}

