#include <iostream>
#include <string>
#include <vector>
#include "ElectricElements.h"
#include "Diode.h"
using namespace std;

DiodeFactory::DiodeFactory() {
	seqType.divider = 0;
	seqType.pos = 0;
}

int DiodeFactory::InputData(vector<ElectricElements> &elementList) {
	cout << "Название?" << endl;
	readStringFromKeyboard(name);
	cout << "Обратное напряжение?" << endl;
	readStringFromKeyboard(revVoltage);
	cout << "Прямой ток?" << endl;
	readStringFromKeyboard(straightCurrent);
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

int DiodeFactory::GenerateComponents(vector < ElectricElements> &elementList)
{
	elementList.push_back(Diode(
		name,
		tu,
		revVoltage,
		straightCurrent,
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

void Diode::SetRevVoltage(string revVoltage)
{
	_revVoltage = revVoltage;
}
void Diode::SetStraightCurrent(string straightCurrent)
{
	_straightCurrent = straightCurrent;
}

string Diode::GetRevVoltage()
{
	return _revVoltage;
}

string Diode::GetStraightCurrent()
{
	return _straightCurrent;
}


void Diode::GenerateString(void)
{
	string determinator = ";";
	stringstream data;
	data << "Диод " << GetName() << "-" << GetRevVoltage() << " В" 
		<< "-" << GetStraightCurrent() << " А" << " " << GetTU() << " ТУ";
	data << determinator << GetName() << " " << GetTU() << " ТУ";
	data << determinator;
	data << determinator << GetTU() << " ТУ";
	data << determinator << GetRevVoltage();
	data << determinator << GetStraightCurrent();
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
