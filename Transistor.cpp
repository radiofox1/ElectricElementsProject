#include <iostream>
#include <string>
#include <vector>
#include "ElectricElements.h"
#include "Transistor.h"
using namespace std;

TransistorFactory::TransistorFactory() {
	seqType.divider = 0;
	seqType.pos = 0;
}

int TransistorFactory::InputData(vector<ElectricElements> &elementList) {
	cout << "Название?" << endl;
	readStringFromKeyboard(name);
	cout << "ТУ?" << endl;
	readStringFromKeyboard(tu);
	cout << "Тип? (PNP, NPN)" << endl;
	readStringFromKeyboard(type);
	cout << "Производитель?" << endl;
	readStringFromKeyboard(manufacturer);
	cout << "Корпус?" << endl;
	readStringFromKeyboard(package);
	cout << "Название символа в библиотеке (Library Ref)?" << endl;
	readStringFromKeyboard(libraryref);
	cout << "Путь к символу в библиотеке (Library Path)?" << endl;
	readStringFromKeyboard(librarypath);
	cout << "Название посадочного места в библиотеке (Footprint Ref)?" << endl;
	readStringFromKeyboard(footprintref);
	cout << "Название второго посадочного места в библиотеке, если оно есть (Footprint Ref 2)?" << endl;
	readStringFromKeyboard(footprintref2);
	cout << "Путь к посадочному месту в библиотеке (Footprint Path)?" << endl;
	readStringFromKeyboard(footprintpath);
	cout << "Путь к документации на компонент?" << endl;
	readStringFromKeyboard(PDF);

	return GenerateComponents(elementList);
}

int TransistorFactory::GenerateComponents(vector < ElectricElements> &elementList)
{
	elementList.push_back(Transistor(
		name,
		tu,
		type,
		package,
		libraryref,
		librarypath,
		footprintref,
		footprintref2,
		footprintpath,
		PDF,
		manufacturer
	));
	return 0;
}

void Transistor::SetType(string type)
{
	_type = type;
}

string Transistor::GetType()
{
	return _type;
}

void Transistor::GenerateString(void)
{
	string determinator = ";";
	stringstream data;
	data << "Транзистор " << GetName() << "-" << GetType() << " " << GetTU() << " ТУ";
	data << determinator << GetName();
	data << determinator;
	data << determinator << GetTU() << " ТУ";
	data << determinator << GetType();
	data << determinator;
	data << determinator << GetName();
	data << determinator;
	data << determinator << GetLibraryRef();
	data << determinator << GetLibraryPath();
	data << determinator << GetFootprintRef();
	data << determinator << GetFootprintRef2();
	data << determinator << GetFootprintPath();
	data << determinator << GetPDF();
	data << determinator << GetManufacturer();
	data << determinator << GetManufacturer();
	data << determinator;

	SetCsvString(data.str());
}

