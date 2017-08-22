#include <iostream>
#include <string>
#include <vector>
#include "ElectricElements.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Transistor.h"
#include "Diode.h"
#include "Inductor.h"
#include "Microchip.h"
#include "ResonatorQuartz.h"
#include "Connector.h"
#include <limits>
#include <clocale>

#include <Windows.h>

#include <sstream>
#include <iostream>
#include <fstream>
#include <io.h>
#include <fcntl.h>

#include "Shared.h"
#include "Input.h"


using namespace std;

/* Резистор - 1, конденсатор - 2, индуктивность - 3,
   диод - 4, транзистор - 5, микросхема - 6,
   кварцевый резонатор - 7, разъем - 8 */

enum userInputNum {EResistor = 1, ECapacitor, EInductor, EDiode,
	ETransistor, EMicrochip, EResonator, EConnector};



int SaveElementsToFile(vector<ElectricElements> &elementsList, const string &filename) {
	std::fstream OutputFile (filename.c_str(), std::fstream::out);
	if (!OutputFile.good()) {
		cerr << "Ошибка открытия файла\r\n";
		return -1;
	}
	else {
		OutputFile << elementsList.begin()->GetHdrString().c_str() << endl;
		for (auto element = elementsList.begin(); element < elementsList.end(); ++element) {
			OutputFile << element->GetCsvString().c_str() << endl;
		}
		OutputFile.close();
	}
	return 0;
}


 void сapacitorFactory(string name, vector<int> power, vector<int> voltage, vector<int> tke, vector<int> tolerance, string performance, string TU, string manufacturer)
{
	for (int valueIndex = 0; valueIndex < numberOfValues; valueIndex++)
	{
		for (int voltageIndex = 0; voltageIndex < (int)voltage.size(); voltageIndex++)
		{
			for (int powerIndex = 0; powerIndex < (int)power.size(); powerIndex++)
			{
				//for (int tkeIndex = 0; tkeIndex < (int)tke.size(); tkeIndex++)
				{

				}
			}
		}
	}
}
 void inductorFactory(string name, vector<int>precision, vector<int> current, vector<int> resistanse, string TU, string manufacturer)
 {
	 for (int valueIndex = 0; valueIndex < numberOfValues; valueIndex++)
	 {
		 for (int precisionIndex = 0; precisionIndex < (int)precision.size(); precisionIndex++)
		 {
			 for (int currentIndex = 0; currentIndex < (int)current.size(); currentIndex++)
			 {
				 for (int resistanseIndex = 0; resistanseIndex < (int)resistanse.size(); resistanseIndex++)
				 { }
			 }
		 }
	 }
 }


//начало самой программы
int main()
{
	int userInputNum = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string name;
	string manufacturer;
	string tu;
	string package;
	string libraryRef;
	string libraryPath;
	string footprintRef;
	string footprintPath;

	vector<ElectricElements> elementList;
	size_t elementCount = 0;

	ResistorFactory *resistorFactory = new ResistorFactory();
	CapacitorFactory *capacitorFactory = new CapacitorFactory();
	MicrochipFactory *microchipFactory = new MicrochipFactory();
	TransistorFactory *transistorFactory = new TransistorFactory();
	DiodeFactory *diodeFactory = new DiodeFactory();
	ResonatorFactory *resonatorFactory = new ResonatorFactory();
	ConnectorFactory *connectorFactory = new ConnectorFactory();
	InductorFactory *inductorFactory = new InductorFactory();

	do {

		cout << "Введите цифру, соответствующую нужному компоненту: " << endl;
		cout << "Резистор - 1, Кондесатор - 2, Катушка индуктивности - 3, Диод - 4, " << endl;
		cout << "Транзистор - 5, Микросхема - 6, Резонатор - 7, Разъем - 8" << endl;
		cin >> userInputNum;
		cin.clear();
		cin.ignore(10, '\n');
		switch (userInputNum)
		{
		case EResistor:
			resistorFactory->InputData(elementList);
		break;

		case ECapacitor:
			capacitorFactory->InputData(elementList);
		break;

		case EMicrochip:
			microchipFactory->InputData(elementList);
		break;

		case ETransistor:
			transistorFactory->InputData(elementList);
		break;

		case EDiode:
			diodeFactory->InputData(elementList);
		break;

		case EConnector:
			connectorFactory->InputData(elementList);
		break;

		case EResonator:
			resonatorFactory->InputData(elementList);
			break;

		case EInductor:
			inductorFactory->InputData(elementList);
			
		break;

		default:
			cout << "Нет такого элемента" << endl;
			break;
		}
		cout << "Добавлено " << elementList.size() - elementCount << " элементов" << endl;
		elementCount = elementList.size();
		cin.clear();
		cout << "Нажмите Enter чтобы продолжить ввод или любую клавишу чтобы закончить" << endl;
		//cin.get();
		string line;
		getline(cin, line);
		if (line.empty()) {
			continue;
		}
		else {
			break;
		}
	}
	while (1);
	//start generating output file:
	
	SaveElementsToFile(elementList, "elements.csv");

	
	return 0;
}
