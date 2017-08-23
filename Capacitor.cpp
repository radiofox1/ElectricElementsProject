#include <iostream>
#include <string>
#include <vector>
#include "ElectricElements.h"
#include "Capacitor.h"

using namespace std;

CapacitorFactory::CapacitorFactory() {
	seqType.divider = 0;
	seqType.pos = 0;
}

enum CapacitorInputDataSteps
{
	ECapName,
	ECapSequence,
	ECapVoltage,
	ECapTKE,
	ECapTol,
	ECapMinMax,
	ECapPerf,
	ECapTU,
	ECapDev,
	ECapCase,
	ECapLibraryRef,
	ECapLibraryPath,
	ECapFootprintRef,
	ECapFootprintRef2,
	ECapFootprintPath,
	ECapDocPath,
	ECapEnd
};

//����� �������� �� �����
int CapacitorFactory::InputData(vector<ElectricElements> &elementList) 
{
	int curStep = ECapName;
	bool readResult = true;
	while (curStep < ECapEnd)
	{
		switch (curStep)
		{
		case ECapName:
		cout << "��������?" << endl;
		readStringFromKeyboard(name);
		readResult = true;
		break;

		case ECapSequence:
		cout << "��� ����������� ��������? (�������� �����):" << endl;
		readResult = getSequenceType(seqType);
		break;

		case ECapVoltage:
		cout << "����������? (������ ���������)" << endl;
		readResult = readIntFromKeyboard(voltage);
		break;

		case ECapTKE:
		cout << "���? (��������� �����������)" << endl;
		readResult = readStringFromKeyboard(stringtke);
		break;

		case ECapTol:
		cout << "������? (������ ���������)" << endl;
		readResult = readDoubleFromKeyboard(tolerance);
		break;

		case ECapMinMax:
		cout << "����������� � ������������ �������" << endl;
		readResult = readDoubleFromKeyboard(minmax);
		break;

		case ECapPerf:
		cout << "������������� ����������?" << endl;
		readResult = readStringFromKeyboard(performance);
		break;

		case ECapTU:
		cout << "��?" << endl;
		readResult = readStringFromKeyboard(tu);
		break;

		case ECapDev:
		cout << "�������������?" << endl;
		readResult = readStringFromKeyboard(manufacturer);
		break;

		case ECapCase:
		cout << "������?" << endl;
		readResult = readStringFromKeyboard(package);
		break;

		case ECapLibraryRef:
		cout << "�������� ������� � ���������� (Library Ref)?" << endl;
		readResult = readStringFromKeyboard(libraryref);
		break;

		case ECapLibraryPath:
		cout << "���� � ������� � ���������� (Library Path)?" << endl;
		readResult = readStringFromKeyboard(librarypath);
		break;

		case ECapFootprintRef:
		cout << "�������� ����������� ����� � ���������� (Footprint Ref)?" << endl;
		readResult = readStringFromKeyboard(footprintref);
		break;

		case ECapFootprintRef2:
		cout << "�������� ������� ����������� ����� � ����������, ���� ��� ���� (Footprint Ref 2)?" << endl;
		readResult = readStringFromKeyboard(footprintref2);
		break;

		case ECapFootprintPath:
		cout << "���� � ����������� ����� � ���������� (Footprint Path)?" << endl;
		readResult = readStringFromKeyboard(footprintpath);
		break;

		case ECapDocPath:
		cout << "���� � ������������ �� ���������?" << endl;
		readResult = readStringFromKeyboard(PDF);
		break;
		}
		curStep += (readResult ? 1 : -1);
	}

	return GenerateComponents(elementList);
}

int CapacitorFactory::GenerateComponents(vector < ElectricElements> &elementList)
{
	if (minmax.size() != 2) {
		cout << "������ ������ �������������" << endl;
		return -1;
	}
	int _valuetype = 0;
	if (valuetype.size() >= 1) {
		_valuetype = valuetype[0];
	}
	int minIdx = 0;
	int maxIdx = 0;
	int minSize = 0;
	int maxSize = 0;
	GetIndexAndSize(minmax[0], minIdx, minSize);
	GetIndexAndSize(minmax[1], maxIdx, maxSize);

	for (int sizeIdx = minSize; sizeIdx <= maxSize; ++sizeIdx) {
		for (int valueIndex = 0; valueIndex < numberOfValues; valueIndex +=seqType.divider) {
			if (((valueIndex < minIdx) && (sizeIdx == minSize)) || ((valueIndex > maxIdx) && (sizeIdx == maxSize))) {
				continue;//of of order;
			}
			else {
				for (auto voltagePtr = voltage.begin(); voltagePtr < voltage.end(); ++voltagePtr) {

						for (auto tolerancePtr = tolerance.begin(); tolerancePtr < tolerance.end(); ++tolerancePtr) {
							elementList.push_back(Capacitor(
								name,
								_value[valueIndex] * pow(10, sizeIdx),
								*voltagePtr,
								*tolerancePtr,
								tu,
								performance,
								stringtke,
								package,
								_valuetype,
								libraryref,
								librarypath,
								footprintref,
								footprintref2,
								footprintpath,
								PDF,
								manufacturer,
								wordtke
								));
						
					}
				}
			}
		}
	}
	return 0;
}


void Capacitor::SetPerformance(string performance)
{
	_performance = performance;
}

void Capacitor::SetStringTKE(string stringtke)
{
	_stringtke = stringtke;
}


string Capacitor::GetPerformance()
{
	return _performance;
}
string Capacitor::GetStringTKE()
{
	return _stringtke;
}


string Capacitor::RusNominale() {
	string nominale;
	stringstream tmp;
	double value = GetValue();
	int index = 0;
	int size = 0;
	GetIndexAndSize(value, index, size);
	//��������� ���������
	switch (size) {
	case 0:
		tmp << _value[index] << " ��";
		break;
	case 1:
		tmp << _value[index] * 10 << " ��";
		break;
	case 2:
		tmp << _value[index] * 100 << " ��";
		break;
	case 3:
		tmp << _value[index] * 1000 << " ��";
		break;
	case 4:
		tmp << _value[index] / 100 << " ���";
		break;
	case 5:
		tmp << _value[index] / 10 << " ���";
		break;
	case 6:
		tmp << _value[index]  << " ���";
		break;

	}
	nominale = tmp.str();
	std::replace(nominale.begin(), nominale.end(), ',', '.'); // replace all ',' to '.'
	return nominale;
} 

void Capacitor::GenerateString(void)
{
	string determinator = ";";
	stringstream data;
	data << "����������� " << GetName() << "-"
		<< GetVoltage() << " �" << "-"
		<< RusNominale() << "-" << GetTolerance() << "-"
		<< GetStringTKE() << "-"  << GetPerformance()
		<< " " << GetTU() <<  " ��";
	data << determinator << GetName() << "-"
		<< GetVoltage() << " �" << "-";
	data << determinator << GetTolerance() << "-"
		<< GetStringTKE() << "-" << GetPerformance();
	data << determinator << GetTU() << " ��";
	data << determinator << GetVoltage();
	data << determinator << GetTolerance();
	data << determinator << RusNominale();
	data << determinator << RusNominale();
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

