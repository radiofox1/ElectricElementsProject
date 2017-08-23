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
	cout << "��������?" << endl;
	readStringFromKeyboard(name);
	cout << "��?" << endl;
	readStringFromKeyboard(tu);
	cout << "���? (PNP, NPN)" << endl;
	readStringFromKeyboard(type);
	cout << "�������������?" << endl;
	readStringFromKeyboard(manufacturer);
	cout << "������?" << endl;
	readStringFromKeyboard(package);
	cout << "�������� ������� � ���������� (Library Ref)?" << endl;
	readStringFromKeyboard(libraryref);
	cout << "���� � ������� � ���������� (Library Path)?" << endl;
	readStringFromKeyboard(librarypath);
	cout << "�������� ����������� ����� � ���������� (Footprint Ref)?" << endl;
	readStringFromKeyboard(footprintref);
	cout << "�������� ������� ����������� ����� � ����������, ���� ��� ���� (Footprint Ref 2)?" << endl;
	readStringFromKeyboard(footprintref2);
	cout << "���� � ����������� ����� � ���������� (Footprint Path)?" << endl;
	readStringFromKeyboard(footprintpath);
	cout << "���� � ������������ �� ���������?" << endl;
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
	data << "���������� " << GetName() << "-" << GetType() << " " << GetTU() << " ��";
	data << determinator << GetName();
	data << determinator;
	data << determinator << GetTU() << " ��";
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
