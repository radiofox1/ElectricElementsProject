#ifndef ElectricElements_H
#define ElectricElements_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ElectricElements //заголовок класса
{
	public: //открытый раздел класса

		ElectricElements(
			string _type,
			string _name,
			double _value = .0,
			int _voltage = 0,
			int _tolerance = 0,
			string _TU = "none",
			string _package = "none",
			int _valuetype = 0,
			string _libraryref = "none",
			string _librarypath = "none",
			string _footprintref = "none",
			string _footprintref2 = "none",
			string _footprintpath = "none",
			string _PDF = "none",
			string _manufacturer = "none",
			string _wordtolerance = "none",
			string _wordtke = "none"
			
		);//значения по умолчанию
		//объявление функций
		void SetType (string _type);
		void SetName (string _name);
		void SetValue (double _value);
		void SetVoltage (int _voltage);
		void SetTolerance (int _tolerance);
		void SetTU (string _TU);
		void SetPackage(string _package);
		void SetLibraryRef(string _libraryref);
		void SetLibraryPath(string _librarypath);
		void SetFootprintRef(string _footprintref);
		void SetFootprintRef2(string _footprintref2);
		void SetFootprintPath(string _footprintpath);
		void SetPDF(string _PDF);
		void SetManufacturer(string _manufacturer);
		void SetWordTolerance(string _wordtolerance);
		void SetWordTKE(string _wordtke);

		string GetType() const;
		string GetName() const;
		string GetTU() const;
		string GetPackage() const;
		string GetLibraryRef() const;
		string GetLibraryPath() const;
		string GetFootprintRef() const;
		string GetFootprintRef2() const;
		string GetFootprintPath() const;
		string GetPDF() const;
		string GetManufacturer() const;
		string GetWordTolerance() const;
		string GetWordTKE() const;
		double GetValue() const;
		int GetVoltage() const;
		int GetTolerance() const;
		int GetValueType() { return valuetype; };

		void SetCsvString(const string &data) { csvstring = data; };

		string GetCsvString(void) { return csvstring; };
		string GetHdrString(void) { return hdrString; };

		void Print();
		string toString();

	private: //закрытый раздел класса
		static double GetValue(int index);
		static int GetValueSz();
		//поля класса
		string type, name, TU, package, PDF, manufacturer;
		string libraryref, librarypath;
		string footprintref, footprintref2, footprintpath;
		string wordtolerance;
		string wordtke;
		double value;
		int voltage;
		int tolerance;
		string csvstring;
		string hdrString;
		int valuetype;
}; //конец класса
#endif
