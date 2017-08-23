

#include "Input.h"

#define UNDO_MARK '$'

bool getSequenceType(sequence_t &seqType)
{
	cin.sync();
	cin.clear();
	size_t secNumber = sizeof(sequence) / sizeof(sequence_t);
	//отображаем все известные последовательности
	for (size_t i = 1; i < secNumber; ++i) {
		cout << sequence[i].name << ":" << i << ", ";
	}
	std::string line;
	if (seqType.pos) {//если есть, отображаем последнюю имеющуюся
		cout << "[" << seqType.name << "]" << endl;
	}
	getline(cin, line);
	if (line.empty()) {
		return true;//Переиспользуем старые значения
	}
	else {
		if (line[0] == UNDO_MARK)
			return false;
		unsigned int temp;
		std::istringstream iss(line);
		while (iss >> temp)
		{
			if ((temp > 0) && (temp < secNumber))
			{
				seqType.pos = sequence[temp].pos;
				seqType.name = sequence[temp].name;
				seqType.divider = sequence[temp].divider;
			}
			else
			{
				cout << "Значениие '" << temp << "'недопустимо" << endl;
			}
		}
	}
	return true;
}


bool readStringFromKeyboard(string &data)
{
	cin.sync();
	cin.clear();
	std::string line;
	if (!data.empty()) {
		cout << "[" << data.c_str() << "]" << endl;
	}
	getline(cin, line);
	if (line.empty()) {
		return true;//Переиспользуем старые значения
	}
	else {
		if (data[0] == UNDO_MARK)
			return false;
		data = line;//копируем новое значение
	}
	return true;
}

template <typename T>
void readFromKeyboard(vector<T> &elements) {
	cin.sync();
	//cin.ignore();
	cin.clear();
	T elementPtr;
	std::string line;
	if (!elements.empty()) {
		cout << "[";
		for (auto element = elements.begin(); element < elements.end(); ++element) {
			cout << *element << " ";
		}
		cout << "]" << endl;
	}
	getline(cin, line);
	if (line.empty()) {
		return;//Переиспользуем старые значения
	}
	else {
		elements.clear();//очищаем и заново
	}
	std::istringstream iss(line);
	while (iss >> elementPtr)
	{
		//	cout << "element: " << elementPtr << endl;
		if (elementPtr > 0)
		{
			elements.push_back(elementPtr);
		}
		else
		{
			cout << "Значениие '" << elementPtr << "'недопустимо" << endl;
		}
	}

}


bool readDoubleFromKeyboard(vector<double> &elements)
{
	cin.sync();
	//cin.ignore();
	cin.clear();
	double elementPtr;
	std::string line;
	if (!elements.empty()) {
		cout << "[";
		for (auto element = elements.begin(); element < elements.end(); ++element) {
			cout << *element << " ";
		}
		cout << "]" << endl;
	}
	getline(cin, line);
	if (line.empty()) {
		return true;//Переиспользуем старые значения
	}
	else {
		if (line[0] == UNDO_MARK)
			return false;

		elements.clear();//очищаем и заново
	}
	std::istringstream iss(line);
	while (iss >> elementPtr)
	{
	//	cout << "element: " << elementPtr << endl;
		if (elementPtr > 0)
		{
			elements.push_back(elementPtr);
		}
		/*else
		{
			cout << "Значениие '" << elementPtr << "'недопустимо" << endl;
		} */
	}
	return true;
}

bool readIntFromKeyboard(vector<int> &elements)
{
	cin.sync();
	//cin.ignore();
	cin.clear();
	int elementPtr;
	std::string line;
	if (!elements.empty()) {
		cout << "[";
		for (auto element = elements.begin(); element < elements.end(); ++element) {
			cout << *element;
		}
		cout << "]" << endl;
	}
	getline(cin, line);
	if (line.empty()) {
		return true;//Переиспользуем старые значения
	}
	else {
		if (line[0] == UNDO_MARK)
			return false;

		elements.clear();//очищаем и заново
	}
	std::istringstream iss(line);
	while (iss >> elementPtr)
	{
		//cout << "element: " << elementPtr << endl;
		if (elementPtr > 0)
		{
			elements.push_back(elementPtr);
		}
		/*else
		{
			cout << "Значениие '" << elementPtr << "'недопустимо" << endl;
		} */
	}
	return true;
}

void GetIndexAndSize(double data, int &index, int &size) {
	if (data < 1) {

		size = 0;//не умеем в такую мелочь
	}
	else {
		size = 0;
		if ((data + .000001) > 10) {
			while ((data + .000001) > 10) {
				data /= 10;
				size += 1;
			}
		}
		//находим номер индекса:
		while ((_value[index] + .000001) < data) {
			index++;
		}
	}
}