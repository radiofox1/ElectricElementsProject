#ifndef Inductor_H
#define Inductor_H

#include <iostream>
#include <string>
#include <vector>
#include "Input.h"
#include <limits>
#include "Sequence.h"

class InductorFactory
{
public:
	InductorFactory();
	int InputData(vector < ElectricElements> &elementList);

private:

	int GenerateComponents(vector < ElectricElements> &elementList);
	sequence_t seqType;
	string name;
	string tu;
	string induction;
	string current;
	string inclimat;
	string precision;
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

class Inductor: public ElectricElements  //заголовок класса
{
	public: //открытый раздел класса
	//точность, ток(напряжение) и климатическое исполнение
	Inductor (
		string name,
		string current,
		string induction,
		string inclimat,
		string precision,
		string TU,
		string package,
		string libraryref,
		string librarypath,
		string footprintref,
		string footprintref2,
		string footprintpath,
		string PDF,
		string manufacturer
	):
		ElectricElements("Катушка индуктивности", name, 0, 0, 0, TU, package, 0, 
			libraryref, librarypath, footprintref, footprintref2, footprintpath, PDF, manufacturer)
	{

		_package = package;
		_induction = induction;
		_current = current;
		_inclimat = inclimat;
		_precision = precision;
		GenerateString();
	
	}
		//объявление функций

		void GenerateString();
		void SetInduction(string induction);
		void SetCurrent (string current);
		void SetInclimat(string inclimat);
		void SetPrecision(string precision);
		string GetInduction();
		string GetCurrent();
		string GetInclimat();
		string GetPrecision();

	private: //закрытый раздел класса
		//поля класса
		string _package; 
		string _induction;
		string _current;
		string _inclimat;
		string _precision;

}; //конец класса

#endif
