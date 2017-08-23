#include <iostream>
#include <string>
#include <vector>
#include "ElectricElements.h"
#include "ResonatorQuartz.h"
using namespace std;

ResonatorFactory::ResonatorFactory() {
	seqType.divider = 0;
	seqType.pos = 0;
}

int ResonatorFactory::InputData(vector<ElectricElements> &elementList) {
	cout << "Название?" << endl;
	readStringFromKeyboard(name);
	cout << "Точность настройки?" << endl;
	readStringFromKeyboard(precisionset);
	cout << "Стабильность?" << endl;
	readStringFromKeyboard(stability);
	cout << "Номинальная частота?" << endl;
	readStringFromKeyboard(frequency);
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

int ResonatorFactory::GenerateComponents(vector < ElectricElements> &elementList)
{
	elementList.push_back(ResonatorQuartz(
		name,
		precisionset,
		stability,
		frequency,
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

void ResonatorQuartz::SetPrecisionset(string precisionset)
{
	_precisionset = precisionset;
}
void ResonatorQuartz::SetStability(string stability)
{
	_stability = stability;
}

void ResonatorQuartz::SetFrequency(string frequency)
{
	_frequency = frequency;
}

string ResonatorQuartz::GetPrecisionset()
{
	return _precisionset;
}

string ResonatorQuartz::GetStability()
{
	return _stability;
}

string ResonatorQuartz::GetFrequency()
{
	return _frequency;
}


void ResonatorQuartz::GenerateString(void)
{
	string determinator = ";";
	stringstream data;
	data << "Резонатор кварцевый " << GetName() << "-" << GetPrecisionset() <<
	 "-" << GetStability() << " " << GetFrequency() << " " << GetTU() << " ТУ";
	data << determinator << GetName() << "-" << GetPrecisionset() << "-";
	data << determinator << GetStability() << " " << GetFrequency();
	data << determinator << GetTU() << " ТУ";
	data << determinator << GetFrequency();
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
