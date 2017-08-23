#include <iostream>
#include <string>
#include <vector>
#include "ElectricElements.h"
#include "Inductor.h"
using namespace std;

InductorFactory::InductorFactory() {
	seqType.divider = 0;
	seqType.pos = 0;
}

int InductorFactory::InputData(vector<ElectricElements> &elementList) {
	cout << "Название?" << endl;
	readStringFromKeyboard(name);
	cout << "Напряжение (ток)?" << endl;
	readStringFromKeyboard(current);
	cout << "Номинальное значение и приставка?" << endl;
	readStringFromKeyboard(induction);
	cout << "Климатическое исполнение?" << endl;
	readStringFromKeyboard(inclimat);
	cout << "Допуск?" << endl;
	readStringFromKeyboard(precision);
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

int InductorFactory::GenerateComponents(vector < ElectricElements> &elementList)
{
	elementList.push_back(Inductor(
		name,
		current,
		induction,
		inclimat,
		precision,
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

void Inductor::SetCurrent(string current)
{
	_current = current;
}
void Inductor::SetInduction(string induction)
{
	_induction = induction;
}

void Inductor::SetInclimat(string inclimat)
{
	_inclimat = inclimat;
}

void Inductor::SetPrecision(string precision)
{
	_precision = precision;
}
string Inductor::GetCurrent()
{
	return _current;
}

string Inductor::GetInduction()
{
	return _induction;
}

string Inductor::GetInclimat()
{
	return _inclimat;
}

string Inductor::GetPrecision()
{
	return _precision;
}

void Inductor::GenerateString(void)
{
	string determinator = ";";
	stringstream data;
	data << "Катушка индуктивности " << GetName() << "-" << GetCurrent() <<
		 "-" << GetInduction() << "+-" << GetPrecision() << "%" << 
		"-" << GetInclimat() << " " << GetTU() << " ТУ";
	data << determinator << GetName() << "-" << GetCurrent() <<
		"-";
	data << determinator << GetInduction() << "+-" << GetPrecision() << "%" <<
		"-" << GetInclimat();
	data << determinator << GetTU() << " ТУ";
	data << determinator << GetCurrent();
	data << determinator << "+-" << GetPrecision() << "%";
	data << determinator << GetInduction();
	data << determinator << GetInduction();
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
