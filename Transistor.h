#ifndef Transistor_H
#define Transistor_H

#include <iostream>
#include <string>
#include <vector>
#include "Input.h"
#include <limits>
#include "Sequence.h"
using namespace std;

class TransistorFactory
{
public:
	TransistorFactory();
	int InputData(vector < ElectricElements> &elementList);

private:

	int GenerateComponents(vector < ElectricElements> &elementList);
	sequence_t seqType;
	string name;
	string tu;
	string type;
	string package;
	string manufacturer;
	string libraryref;
	string librarypath;
	string footprintref;
	string footprintref2;
	string footprintpath;
	string PDF;
};

using namespace std;

class Transistor : public ElectricElements  //заголовок класса
{
public: //открытый раздел класса
	Transistor(
		string name,
		string TU,
		string type,
		string package, //корпус
		string libraryref,
		string librarypath,
		string footprintref,
		string footprintref2,
		string footprintpath,
		string PDF,
		string manufacturer
	) :
		ElectricElements("Транзистор", name, 0, 0, 0, TU, package, 0,
			libraryref, librarypath, footprintref, footprintref2, footprintpath, PDF, manufacturer)
	{
		_package = package;
		_type = type;
		GenerateString();

	}
	void GenerateString();
	void SetType(string type);
	string GetType();

private: //закрытый раздел класса
		 //поля класса
	string _package;
	string _type;
}; //конец класса

#endif


