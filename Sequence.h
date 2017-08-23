#pragma once

#include <string>

typedef struct _seqence_t {
	unsigned int pos;
	std::string name;
	unsigned int divider;
} sequence_t;
//ряды номиналов
static sequence_t sequence[] =
{ { 0, "NUL", 0 } ,
{1, "E192", 1} ,
{2, "E96", 2 } ,
{3, "E48", 4 } ,
{4, "E24", 8 } ,
{5, "E12", 16 } ,
{6, "E6", 32 } };


class Sequence
{
public:
	Sequence();
	~Sequence();
private:
	int type;
};

