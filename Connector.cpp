#include <iostream>
#include <string>
#include <vector>
#include "ElectricElements.h"
#include "Connector.h"
using namespace std;

ConnectorFactory::ConnectorFactory() {
	seqType.divider = 0;
	seqType.pos = 0;
}

int ConnectorFactory::InputData(vector<ElectricElements> &elementList) {
	cout << "Название?" << endl;
	readStringFromKeyboard(name);
	cout << "Количество контактов?" << endl;
	readStringFromKeyboard(pin);
	cout << "Часть разъема (Ш - вилка, Г - розетка)?" << endl;
	readStringFromKeyboard(contype);
	cout << "Покрытие контактов?" << endl;
	readStringFromKeyboard(covering);
	cout << "Климатическое исполнение?" << endl;
	readStringFromKeyboard(climat);
	cout << "ТУ?" << endl;
	readStringFromKeyboard(tu);
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

int ConnectorFactory::GenerateComponents(vector < ElectricElements> &elementList)
{
	elementList.push_back(Connector(
		name,
		pin,
		contype,
		covering,
		climat,
		tu,
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

void Connector::SetPin(string pin)
{
	_pin = pin;
}
void Connector::SetContype(string contype)
{
	_contype = contype;
}

void Connector::SetCovering(string covering)
{
	_covering = covering;
}

void Connector::SetClimat(string climat)
{
	_climat = climat;
}

string Connector::GetPin()
{
	return _pin;
}

string Connector::GetContype()
{
	return _contype;
}

string Connector::GetCovering()
{
	return _covering;
}

string Connector::GetClimat()
{
	return _climat;
}

void Connector::GenerateString(void)
{
	string determinator = ";";
	stringstream data;
	data << "Разъем " << GetName() << "-" << GetPin() <<
		"-" << GetContype() << " " << GetCovering() << GetClimat() << GetTU() << " ТУ";
	data << determinator << GetName() << "-" << GetPin() << "-";
	data << determinator << GetContype() << " " << GetCovering() << GetClimat();
	data << determinator << GetTU() << " ТУ";
	data << determinator << GetPin();
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
