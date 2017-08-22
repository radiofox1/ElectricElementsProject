#ifndef ResonatorQuartz_H
#define ResonatorQuartz_H

#include <iostream>
#include <string>
#include <vector>
#include "Input.h"
#include <limits>
#include "Sequence.h"

class ResonatorFactory
{
public:
	ResonatorFactory();
	int InputData(vector < ElectricElements> &elementList);

private:

	int GenerateComponents(vector < ElectricElements> &elementList);
	sequence_t seqType;
	string name;
	string tu;
	string precisionset;
	string stability;
	string frequency;
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

class ResonatorQuartz: public ElectricElements  //заголовок класса
{
	public: //открытый раздел класса
		ResonatorQuartz(
			string name,
			string precisionset,
			string stability,
			string frequency,
			string TU,
			string package,
			string libraryref,
			string librarypath,
			string footprintref,
			string footprintref2,
			string footprintpath,
			string PDF,
			string manufacturer
		) : //точность настройки, стабильность, частота
			ElectricElements("Резонатор кварцевый", name, 0, 0, 0, TU, package, 0,
				libraryref, librarypath, footprintref, footprintref2, footprintpath, PDF, manufacturer) 
		{

			_package = package;
			_precisionset = precisionset;
			_stability = stability;
			_frequency = frequency;
			GenerateString();
		}
		//объявление функций
		void GenerateString();
		void SetFrequency (string frequency);
		void SetStability (string stability);
		void SetPrecisionset(string precisionset);
		string GetFrequency();
		string GetStability();
		string GetPrecisionset();

	private: //закрытый раздел класса
		//поля класса
		string _package;
		string _frequency;
		string _stability;
		string _precisionset;
}; //конец класса

#endif
