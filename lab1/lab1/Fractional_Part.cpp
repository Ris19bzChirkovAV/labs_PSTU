#include "Fractional_Part.h"
#include <iostream>

using namespace std;

void fractional::init(int F, int S)
{
	first = F;
	second = S;
}

void fractional::show()
{
	cout << first << "\t" << second << endl;
}

int fractional::ipart()
{
	cout << "Целая часть вашей дроби равна = " << (first / second) << endl;
	return (first / second);
}