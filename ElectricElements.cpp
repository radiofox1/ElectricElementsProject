#include <iostream>
#include <string>
#include <vector>
#include "ElectricElements.h"
using namespace std;


static double _value[] = { 
		1.00, 1.01, 1.02, 1.04, 1.05, 1.06, 1.07, 1.09, 1.10, 1.11, 1.13,
		1.14, 1.15, 1.17, 1.18, 1.20, 1.21, 1.23, 1.24, 1.26, 1.27, 1.29,
		1.30, 1.32, 1.33, 1.35, 1.37, 1.38, 1.40, 1.42, 1.43, 1.45, 1.47,
		1.49, 1.50, 1.52, 1.54, 1.56, 1.58, 1.60, 1.62, 1.64, 1.65, 1.67,
		1.69, 1.72, 1.74, 1.76, 1.78, 1.80, 1.82, 1.84, 1.87, 1.89, 1.91,
		1.93, 1.96, 1.98, 2.00, 2.03, 2.05, 2.08, 2.10, 2.13, 2.15, 2.18,
		2.21, 2.23, 2.26, 2.29, 2.32, 2.34, 2.37, 2.40, 2.43, 2.46, 2.49,
		2.52, 2.55, 2.58, 2.61, 2.64, 2.67, 2.71, 2.74, 2.77, 2.80, 2.84,
		2.87, 2.91, 2.94, 2.98, 3.01, 3.05, 3.09, 3.12, 3.16, 3.20, 3.24,
		3.28, 3.32, 3.36, 3.40, 3.44, 3.48, 3.52, 3.57, 3.61, 3.65, 3.70,
		3.74, 3.79, 3.83, 3.88, 3.92, 3.97, 4.02, 4.07, 4.12, 4.17, 4.22,
		4.27, 4.32, 4.37, 4.42, 4.48, 4.53, 4.59, 4.64, 4.70, 4.75, 4.81,
		4.87, 4.93, 4.99, 5.05, 5.11, 5.17, 5.23, 5.30, 5.36, 5.42, 5.49,
		5.56, 5.62, 5.69, 5.76, 5.83, 5.90, 5.97, 6.04, 6.12, 6.19, 6.26,
		6.34, 6.42, 6.49, 6.57, 6.65, 6.73, 6.81, 6.90, 6.98, 7.06, 7.15,
		7.23, 7.32, 7.41, 7.50, 7.59, 7.68, 7.77, 7.87, 7.96, 8.06, 8.16,
		8.25, 8.35, 8.45, 8.56, 8.66, 8.76, 8.87, 8.98, 9.09, 9.20, 9.31, 
		9.42, 9.53, 9.65, 9.76, 9.88 }; ////инициализация массива значений согласно ряду Е192

//инициализация члена класса
double GetValue(int index)
{
	return _value[index];
}

int GetValueSz()
{
	return (sizeof(_value)/sizeof(_value[0]));
}

ElectricElements::ElectricElements (
		string _type,
		string _name,
		double _value,
		int _voltage,
		int _tolerance,
		string _TU,
		string _package,
		int _valuetype,
	    string _libraryref,
		string _librarypath,
		string _footprintref,
		string _footprintref2,
		string _footprintpath,
		string _PDF,
		string _manufacturer,
		string _wordtolerance,
		string _wordtke
	)
{
	type = _type;
	name = _name;
	value = _value;
	voltage = _voltage;
	tolerance = _tolerance;
	TU = _TU,
	package = _package;
	valuetype = _valuetype;
	libraryref = _libraryref;
	librarypath = _librarypath;
	librarypath = _librarypath;
	footprintref = _footprintref;
	footprintref2 = _footprintref2;
	footprintpath = _footprintpath;
	PDF = _PDF;
	manufacturer = _manufacturer;
	wordtolerance = _wordtolerance;
	wordtke = _wordtke;
//	valuetype = _valuetype;

		
	string determinator = ";";
	//шапка таблицы в выходном файле
	hdrString = "Part Number" + determinator + "Name1" + determinator + "Name2" + determinator + "TU" + determinator + "Base Par" + determinator + "Add_Atr" +
		determinator + "ValueGOST" + determinator + "Value" + determinator + "Library Ref" + determinator + "Library Path" + determinator + "Footprint Ref"
		+ determinator + "Footprint Ref 2"  + determinator + "Footprint Path" + determinator + "PDF" + determinator + "Manufacturer" + determinator + 
		"ManufacturerEn" + determinator + "Provider";
}
//функции получения новых значений
void ElectricElements::SetType(string _type)
{
	type = _type;
}

void ElectricElements::SetName(string _name)
{
	name = _name;
}

void ElectricElements::SetValue(double _value)
{
	value = _value;
}

void ElectricElements::SetVoltage(int _voltage)
{
	voltage = _voltage;
}

void ElectricElements::SetTolerance(int _tolerance)
{
	tolerance = _tolerance;
}

void ElectricElements::SetTU(string _TU)
{
	TU = _TU;
}

void ElectricElements::SetPackage(string _package)
{
	package = _package;
}

void ElectricElements::SetLibraryRef(string _libraryref)
{
	libraryref = _libraryref;
}

void ElectricElements::SetLibraryPath(string _librarypath)
{
	librarypath = _librarypath;
}

void ElectricElements::SetFootprintRef(string _footprintref)
{
	footprintref = _footprintref;
}

void ElectricElements::SetFootprintRef2(string _footprintref2)
{
	footprintref2 = _footprintref2;
}

void ElectricElements::SetFootprintPath(string _footprintpath)
{
	footprintpath = _footprintpath;
}

void ElectricElements::SetPDF(string _PDF)
{
	PDF = _PDF;
}

void ElectricElements::SetManufacturer(string _manufacturer)
{
	manufacturer = _manufacturer;
}

void ElectricElements::SetWordTolerance(string _wordtolerance)
{
	wordtolerance = _wordtolerance;
}

void ElectricElements::SetWordTKE(string _wordtke)
{
	wordtke = _wordtke;
}

string ElectricElements::GetType() const
{
	return type;
}

string ElectricElements::GetName() const
{
	return name;
}

double ElectricElements::GetValue() const
{
	return value;
}

int ElectricElements::GetVoltage() const
{
	return voltage;
}

int ElectricElements::GetTolerance() const
{
	return tolerance;
}

string ElectricElements::GetTU() const
{
	return TU;
}

string ElectricElements::GetPackage() const
{
	return package;
}

string ElectricElements::GetLibraryRef() const
{
	return libraryref;
}

string ElectricElements::GetLibraryPath() const
{
	return librarypath;
}

string ElectricElements::GetFootprintRef() const
{
	return footprintref;
}

string ElectricElements::GetFootprintRef2() const
{
	return footprintref2;
}

string ElectricElements::GetFootprintPath() const
{
	return footprintpath;
}

string ElectricElements::GetPDF() const
{
	return PDF;
}

string ElectricElements::GetManufacturer() const
{
	return manufacturer;
}

string ElectricElements::GetWordTolerance() const
{
	return wordtolerance;
}

string ElectricElements::GetWordTKE() const
{
	return wordtke;
}

void ElectricElements::Print() {


	std::cout << "Òèï: " << type << ", Èìÿ: " << name << ", ÒÓ: " << TU << ", " << value << ", " << voltage << ", " << tolerance << std::endl;

}
