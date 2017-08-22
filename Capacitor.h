#ifndef Capacitor_H
#define Capacitor_H

#include <iostream>
#include <string>
#include <vector>
#include "Input.h"
#include <limits>
#include "Sequence.h"

#include <algorithm>

class CapacitorFactory
{
public:
	CapacitorFactory();
	int InputData(vector < ElectricElements> &elementList);

private:

	int GenerateComponents(vector < ElectricElements> &elementList);
	sequence_t seqType;
	string name;
	string manufacturer;
	string tu;
	string package;
	string performance; //климатическое исполнение
	string stringtke;
	string libraryref;
	string librarypath;
	string footprintref;
	string footprintref2;
	string footprintpath;
	string PDF;
	string wordtke;
	vector<int> voltage;
	//vector<int> tke;
	vector<double> tolerance;
	vector<double> minmax;
	vector<int> valuetype;
};

using namespace std;

class Capacitor : public ElectricElements  //заголовок класса
{
public: //открытый раздел класса
	Capacitor(
			string name,
			double value,
			int voltage,
			double tolerance,
			string TU,
			string package,
			string performance,
			string stringtke,
			int _valuetype,
			string libraryref,
			string librarypath,
			string footprintref,
			string footprintref2,
			string footprintpath,
			string PDF,
			string manufacturer,
			string wordtke
			):ElectricElements("Конденсатор", name, value, voltage, tolerance, TU, package, _valuetype, 
				libraryref, librarypath, footprintref, footprintref2, footprintpath, PDF, manufacturer, wordtke)

	{
		_performance = performance;
		_stringtke = stringtke;
		GenerateString();
	}

	//объявление функций
		void GenerateString();
		void SetPerformance(string _performance);
		void SetStringTKE(string _stringtke);
		string GetPerformance();
		string GetStringTKE();

private: //закрытый раздел класса
		//поля класса
	string RusNominale();
	string _performance;
	string _stringtke;
}; //конец класса

#endif 
