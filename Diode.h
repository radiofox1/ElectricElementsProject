#ifndef Diode_H
#define Diode_H

#include <iostream>
#include <string>
#include <vector>
#include "Input.h"
#include <limits>
#include "Sequence.h"

class DiodeFactory
{
public:
	DiodeFactory();
	int InputData(vector < ElectricElements> &elementList);

private:

	int GenerateComponents(vector < ElectricElements> &elementList);
	sequence_t seqType;
	string name;
	string tu;
	string revVoltage;
	string straightCurrent;
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

class Diode : public ElectricElements  //заголовок класса
{
public: //открытый раздел класса
	Diode(
		string name,
		string TU,
		string revVoltage,
		string straightCurrent,
		string package, //корпус
		string libraryref,
		string librarypath,
		string footprintref,
		string footprintref2,
		string footprintpath,
		string PDF,
		string manufacturer
	) :
		ElectricElements("Диод", name, 0, 0, 0, TU, package, 0,
			libraryref, librarypath, footprintref, footprintref2, footprintpath, PDF, manufacturer)
	{
		_package = package;
		_revVoltage = revVoltage;
		_straightCurrent = straightCurrent;
		GenerateString();

	}
	//объявление функций
	void GenerateString();
	void SetRevVoltage(string revVoltage);
	void SetStraightCurrent(string _straightCurrent);
	string GetRevVoltage();
	string GetStraightCurrent();

private: //закрытый раздел класса
		 //поля класса
	string _package;
	string _revVoltage;
	string _straightCurrent;
}; //конец класса

#endif



