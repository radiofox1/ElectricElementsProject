#include <iostream>
#include <string>
#include <vector>
#include "ElectricElements.h"
#include "Microchip.h"
using namespace std;

MicrochipFactory::MicrochipFactory() {
	seqType.divider = 0;
	seqType.pos = 0;
}

int MicrochipFactory::InputData(vector<ElectricElements> &elementList) {
	cout << "Название?" << endl;
	readStringFromKeyboard(name);
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

int MicrochipFactory::GenerateComponents(vector < ElectricElements> &elementList)
{
	elementList.push_back(Microchip(
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

void Microchip::GenerateString(void)
{
	string determinator = ";";
	stringstream data;
	data << "Микросхема " << GetName() << GetTU() << " ТУ";
	data << determinator << GetName();
	data << determinator << GetTU() << " ТУ";
	data << determinator;
	data << determinator << GetPackage();
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
