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
	cout << "��������?" << endl;
	readStringFromKeyboard(name);
	cout << "�������� ����������?" << endl;
	readStringFromKeyboard(revVoltage);
	cout << "������ ���?" << endl;
	readStringFromKeyboard(straightCurrent);
	cout << "��?" << endl;
	readStringFromKeyboard(tu);
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
	data << "���� " << GetName() << "-" << GetRevVoltage() << " �" 
		<< "-" << GetStraightCurrent() << " �" << " " << GetTU() << " ��";
	data << determinator << GetName() << " " << GetTU() << " ��";
	data << determinator;
	data << determinator << GetTU() << " ��";
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
