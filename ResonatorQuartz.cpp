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
	cout << "��������?" << endl;
	readStringFromKeyboard(name);
	cout << "�������� ���������?" << endl;
	readStringFromKeyboard(precisionset);
	cout << "������������?" << endl;
	readStringFromKeyboard(stability);
	cout << "����������� �������?" << endl;
	readStringFromKeyboard(frequency);
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
	data << "��������� ��������� " << GetName() << "-" << GetPrecisionset() <<
	 "-" << GetStability() << " " << GetFrequency() << " " << GetTU() << " ��";
	data << determinator << GetName() << "-" << GetPrecisionset() << "-";
	data << determinator << GetStability() << " " << GetFrequency();
	data << determinator << GetTU() << " ��";
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
