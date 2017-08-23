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
	cout << "��������?" << endl;
	readStringFromKeyboard(name);
	cout << "���������� ���������?" << endl;
	readStringFromKeyboard(pin);
	cout << "����� ������� (� - �����, � - �������)?" << endl;
	readStringFromKeyboard(contype);
	cout << "�������� ���������?" << endl;
	readStringFromKeyboard(covering);
	cout << "������������� ����������?" << endl;
	readStringFromKeyboard(climat);
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
	data << "������ " << GetName() << "-" << GetPin() <<
		"-" << GetContype() << " " << GetCovering() << GetClimat() << GetTU() << " ��";
	data << determinator << GetName() << "-" << GetPin() << "-";
	data << determinator << GetContype() << " " << GetCovering() << GetClimat();
	data << determinator << GetTU() << " ��";
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
