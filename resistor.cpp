#include <iostream>
#include <string>
#include <vector>
#include "ElectricElements.h"
#include "Resistor.h"


using namespace std;

ResistorFactory::ResistorFactory() {
	seqType.divider = 0;
	seqType.pos = 0;
}

enum ResistorInputDataSteps
{
	EResName,
	EResSequence,
	EResPower,
	EResVoltage,
	EResTKS,
	EResTol,
	EResMinMax,
	EResType,
	EResTU,
	EResDev,
	EResCase,
	EResLibraryRef,
	EResLibraryPath,
	EResFootprintRef,
	EResFootprintRef2,
	EResFootprintPath,
	EResDocPath,
	EResEnd
};

//Вывод запросов на экран
int ResistorFactory::InputData(vector<ElectricElements> &elementList)
{
	int curStep = EResName;
	bool readResult = true;
	while(curStep < EResEnd)
	{
		switch(curStep)
		{
		case EResName:
			cout << "Название?" << endl;
			readStringFromKeyboard(name);
			readResult = true; //cannot move to the prev value since it is first one
			break;

		case EResSequence:
			cout << "Ряд номинальных значений? (выберите цифру):" << endl;
			readResult = getSequenceType(seqType);
			break;

		case EResPower:
			cout << "Мощность? (через пробел)" << endl;
			readResult = readDoubleFromKeyboard(power);
			break;

		case EResVoltage:
			cout << "Напряжение? (через пробел)" << endl;
			readResult = readIntFromKeyboard(voltage);
			break;

		case EResTKS:
			cout << "ТКС? (через пробел)" << endl;
			readResult = readIntFromKeyboard(tks);
			break;

		case EResTol:
			cout << "Допуск? (через пробел)" << endl;
			readResult = readDoubleFromKeyboard(tolerance);
			break;

		case EResMinMax:
			cout << "Минимальное и максимальное сопротивление?" << endl;
			readResult = readDoubleFromKeyboard(minmax);
			break;

		case EResType:
			cout << "Схема наименования: 0 - отечественная, 1 - импортная (прим: 2к1)" << endl;
			readResult = readIntFromKeyboard(valuetype);
			break;

		case EResTU:
			cout << "ТУ? (если есть)" << endl;
			readResult = readStringFromKeyboard(tu);
			break;

		case EResDev:
			cout << "Производитель?" << endl;
			readResult = readStringFromKeyboard(manufacturer);
			break;

		case EResCase:
			cout << "Корпус?" << endl;
			readResult = readStringFromKeyboard(package);
			break;

		case EResLibraryRef:
			cout << "Название символа в библиотеке (Library Ref)?" << endl;
			readResult = readStringFromKeyboard(libraryref);
			break;

		case EResLibraryPath:
			cout << "Путь к символу в библиотеке (Library Path)?" << endl;
			readResult = readStringFromKeyboard(librarypath);
			break;

		case EResFootprintRef:
			cout << "Название посадочного места в библиотеке (Footprint Ref)?" << endl;
			readResult = readStringFromKeyboard(footprintref);
			break;

		case EResFootprintRef2:
			cout << "Название второго посадочного места в библиотеке, если оно есть (Footprint Ref 2)?" << endl;
			readResult = readStringFromKeyboard(footprintref2);
			break;

		case EResFootprintPath:
			cout << "Путь к посадочному месту в библиотеке (Footprint Path)?" << endl;
			readResult = readStringFromKeyboard(footprintpath);
			break;

		case EResDocPath:
			cout << "Путь к документации на компонент?" << endl;
			readResult = readStringFromKeyboard(PDF);
			break;
		}
		curStep += (readResult ? 1 : -1);
	}

	return GenerateComponents(elementList);
}

int ResistorFactory::GenerateComponents(vector < ElectricElements> &elementList)
{
	if (minmax.size() != 2) {
		cout << "Ошибка границ сопротивлений" << endl;
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
					for (auto powerPtr = power.begin(); powerPtr < power.end(); ++powerPtr) {
						for (auto tksPtr = tks.begin(); tksPtr < tks.end(); ++tksPtr) {
							for (auto tolerancePtr = tolerance.begin(); tolerancePtr < tolerance.end(); ++tolerancePtr) {
								elementList.push_back(Resistor(
									name,
									_value[valueIndex] * pow(10, sizeIdx),
									*voltagePtr,
									*tolerancePtr,
									tu,
									*powerPtr,
									*tksPtr,
									package,
									_valuetype,
									libraryref,
									librarypath,
									footprintref,
									footprintref2,
									footprintpath,
									PDF,
									manufacturer,
									wordtolerance
									));
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

void Resistor::SetPower (double power)
{
	_power = power;
}
void Resistor::SetTKS (int TKS)
{
	_TKS = TKS;
}

float Resistor::GetPower()
{
	return _power;
}

int Resistor::GetTKS()
{
	return _TKS;
}

string Resistor::RusNominale() {
	string nominale;
	stringstream tmp;
	double value = GetValue();
	int index = 0;
	int size = 0;
	GetIndexAndSize(value, index, size);
	//приставки номиналов
	switch (size) {
	case 0:
		tmp << value << " Ом";
		break;
	case 1:
		tmp << _value[index] * 10 << " Ом";
		break;
	case 2:
		tmp << _value[index] * 100 << " Ом";
		break;
	case 3:
		tmp << _value[index] << " кОм";
		break;
	case 4:
		tmp << _value[index] * 10 << " кОм";
		break;
	case 5:
		tmp << _value[index] * 100 << " кОм";
		break;
	case 6:
		tmp << _value[index] << " MОм";
		break;
	case 7:
		tmp << _value[index] * 10 << "МОм";
		break;
	case 8:
		tmp << _value[index] * 100 << "МОм";
		break;
	case 9:
		break;
	}
	nominale = tmp.str();
	std::replace(nominale.begin(), nominale.end(), ',', '.'); // replace all ',' to '.'
	return nominale;
}

//Обработка зарубежных номиналов вида 1R2
string Resistor::ImportNominale() {
	stringstream tmp;


	double value = GetValue();
	int index = 0;
	int size = 0;
	GetIndexAndSize(value, index, size);
	
	int integer = 0; 
	double modulo = 0;

	switch (size) {
	case 0:
	case 3:
	case 6:
		integer = static_cast<int>(_value[index]);
		modulo = _value[index] - integer;
		break;
	case 1:
	case 4:
	case 7:
		integer = static_cast<int>(_value[index] *10);
		modulo = _value[index]*10 - integer;
		break;
	case 2:
	case 5:
	case 8:
		integer = static_cast<int>(_value[index]*100);
		modulo = _value[index]*100 - integer;
		break;
	}
	string letter;
	switch (size) {
	case 0:
	case 1:
	case 2:
		letter = "R";
		break;
	case 3:
	case 4:
	case 5:
		letter = "K";
		break;
	case 6:
	case 7:
	case 8:
		letter = "M";
		break;
	default:
		letter = "WTF?";
		break;
	}

	tmp << modulo;
	string sz(tmp.str());
	std::stringstream().swap(tmp);
	size_t pos = sz.rfind(L'.');
	if (pos != string::npos)
		sz = string(sz.c_str() + pos + 1);

	tmp << integer << letter;
	if (modulo > 0.000001) {
		tmp  << sz;
	}

	return tmp.str();
}

//Вывод в файл
void Resistor::GenerateString(void)
{
	string determinator = ";";
	stringstream data;
	if (GetValueType() != 1) {
		data << "Резистор " << GetName() << "-"
			<< GetPower() << "-"
			<< GetVoltage() << " В-"
			<< RusNominale() << "-"
			<< GetTKS() << " ppm"
			<< "+-" << GetTolerance() << "%"
			<< " " << GetTU() << " ТУ"; 
		data << determinator << GetName() << "-"
			<< GetPower() << "-"
			<< GetVoltage() << " В-";
		data << determinator << RusNominale() << "-"
			<< GetTKS() << " ppm"
			<< "+-" << GetTolerance() << "%";
		data << determinator << GetTU() << " ТУ";
		data << determinator << GetVoltage();
		data << determinator << "+-" << GetTolerance() << "%";
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
	else
	{
		data << "Резистор " << GetName() << GetPackage()
			<< GetWordTolerance() << "R" << "-"
			<< GetPower() << "W"
			<< ImportNominale() << "L";
		data << determinator << GetName() << GetPackage()
			<< GetWordTolerance() << "R" << "-"
			<< GetPower() << "W"
			<< ImportNominale() << "L";
		data << determinator;
		data << determinator << GetTU();
		data << determinator << GetVoltage() << " В";
		data << determinator << GetWordTolerance();
		data << determinator << ImportNominale();
		data << determinator << ImportNominale();
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
}
