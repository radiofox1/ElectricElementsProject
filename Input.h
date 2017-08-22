#pragma once


#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#include "Shared.h"
#include "Sequence.h"

using namespace std;

bool getSequenceType(sequence_t &seqType);

bool readStringFromKeyboard(string &data);

bool  readDoubleFromKeyboard(vector<double> &data);

bool readIntFromKeyboard(vector<int> &data);

template <typename T>
void readFromKeyboard(vector<T> &elements);

void GetIndexAndSize(double data, int &index, int &size);