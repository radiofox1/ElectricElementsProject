#include <iostream>
#include <string>
#include <vector>
#include "ElectricElements.h"
#include "Condensator.h"
using namespace std;

CondensatorFactory::CondensatorFactory() {
	seqType.divider = 0;
	seqType.pos = 0;
}

int CondensatorFactory::InputData(vector<ElectricElements> &elementList) {
	cout << "Название?" << endl;
	readStringFromKeyboard(name);
	cout << "перформанс?" << endl;
	readStringFromKeyboard(name);
	cout << "Напряжение? (Массив элементов)" << endl;
	readIntFromKeyboard(voltage);
	cout << "ТКС? (Массив элементов)" << endl;
	readIntFromKeyboard(tke);
	cout << "Допуск? (Массив элементов)" << endl;
	readDoubleFromKeyboard(tolerance);
	cout << "Минимальное и максимальное сопротивление" << endl;
	readDoubleFromKeyboard(minmax);
	cout << "ТУ?" << endl;
	readStringFromKeyboard(tu);
	cout << "Производитель?" << endl;
	readStringFromKeyboard(manufacturer);
	cout << "Ряд значений:" << endl;
	getSequenceType(seqType);
	return GenerateComponents(elementList);
}


int CondensatorFactory::GenerateComponents(vector < ElectricElements> &elementList)
{
	if (minmax.size() != 2) {
		cout << "Ошибка границ сопротивлений" << endl;
		return -1;
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

					for (auto tksPtr = tke.begin(); tksPtr < tke.end(); ++tksPtr) {
						for (auto tolerancePtr = tolerance.begin(); tolerancePtr < tolerance.end(); ++tolerancePtr) {
							elementList.push_back(Condensator(
								name,
								_value[valueIndex] * pow(10, sizeIdx),
								*voltagePtr,
								*tolerancePtr,
								tu,
								*tksPtr,
								performance
								));
						}
					}
				}
			}
		}
	}
	return 0;
}

string Condensator::GetCsvString()
{
	stringstream data;
	data << GetName().c_str() << endl;
	

	return data.str();
}
