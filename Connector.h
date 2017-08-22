#ifndef Connector_H
#define Connector_H

#include <iostream>
#include <string>
#include <vector>
#include "Input.h"
#include <limits>
#include "Sequence.h"

class ConnectorFactory
{
public:
	ConnectorFactory();
	int InputData(vector < ElectricElements> &elementList);

private:

	int GenerateComponents(vector < ElectricElements> &elementList);
	sequence_t seqType;
	string name;
	string tu;
	string pin;
	string contype;
	string covering;
	string climat;
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

class Connector : public ElectricElements  //заголовок класса
{
	public: //открытый раздел класса
		//название, количество контактов, тип разъема, покрытие, климатическое исполнение
		Connector (
			string name, 
			string pin,
			string contype,
			string covering,
			string climat,
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
		ElectricElements ("Разъем", name, 0, 0, 0, TU, package, 0,
			libraryref, librarypath, footprintref, footprintref2, footprintpath, PDF, manufacturer) {

			_package = package;
			_pin = pin;
			_contype = contype;
			_covering = covering;
			_climat = climat;
			GenerateString();
		}

		//объявление функций
		void GenerateString();
		void SetPin (string pin);
		void SetContype(string contype);
		void SetCovering(string covering);
		void SetClimat(string climat);
		string GetPin();
		string GetContype();
		string GetCovering();
		string GetClimat();

	private: //закрытый раздел класса
		//поля класса
		string _package;
		string _pin;
		string _contype;
		string _covering;
		string _climat;
}; //конец класса

#endif
