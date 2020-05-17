#include <iostream>
#include "Pair.h"
#include "Fraction.h"
#include <string>
#include "Vector.h"

using namespace std;

void main()
{
	Vector vector(3);
	Pair pair_1;
	cin >> pair_1;
	Fraction pair_2;
	Fraction pair_3(3.14, 7.62);
	Object* p = &pair_1;
	cout << "Pair 1 - class Pair"
		" add to vector\n";
	vector.Add(p);
	pair_2 = pair_3;
	p = &pair_2;
	cout << "Pair 2,3 - class Fraction"
		" add to vector\n";
	vector.Add(p);
	cout << vector << endl;
}

