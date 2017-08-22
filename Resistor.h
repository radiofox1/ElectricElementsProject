#ifndef Resistor_H
#define Resistor_H

#include <iostream>
#include <string>
#include <vector>
#include "Input.h"
#include <limits>
#include "Sequence.h"

#include <algorithm>

class ResistorFactory
{

public:
	ResistorFactory();
	int InputData(vector < ElectricElements> &elementList);

private:

	int GenerateComponents(vector < ElectricElements> &elementList);
	sequence_t seqType;
    string name;
	string manufacturer;
	string tu;
	string package;
	string libraryref;
	string librarypath;
	string footprintref;
	string footprintref2;
	string footprintpath;
	string PDF;
	string wordtolerance;
	vector<double> power;
	vector<int> voltage;
	vector<int> tks;
	vector<double> tolerance;
	vector<double> minmax;
	vector<int> valuetype;
};

using namespace std;

class Resistor: public ElectricElements  //заголовок класса
{
	public: //открытый раздел класса

	Resistor(
			string name,
			double value,
			int voltage,
			int tolerance,
			string TU,
			float power,
			int TKS,
			string package,
		    int _valuetype,
			string libraryref,
			string librarypath,
			string footprintref,
			string footprintref2,
			string footprintpath,
			string PDF,
			string manufacturer,
			string wordtolerance
		):ElectricElements("–езистор", name, value, voltage, tolerance, TU, package, _valuetype, 
			libraryref, librarypath, footprintref, footprintref2, footprintpath, PDF, manufacturer, wordtolerance)
	{
		_power = power;
		_TKS = TKS;
		GenerateString();
		
	}
	//объ€вление функций
		void GenerateString();
		void SetPower (double _power);
		void SetTKS (int _TKS);
		float GetPower();
		int GetTKS();
		string GetNominale();

	private: //закрытый раздел класса
		//пол€ класса

		string RusNominale();
		string ImportNominale();
		float _power;
		int _TKS;
}; //конец класса

#endif
