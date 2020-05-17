#include <iostream>
#include "Pair.h"
#include "Fraction.h"

using namespace std;



void main()
{
	setlocale(LC_ALL,"ru");
	Pair try_first;
	Pair try_second(40, 23);
	cin >> try_first;
	cout << try_first << " " << try_second << endl;
	if (try_first > try_second)
	{
		cout << try_first << endl;
	}
	else if (try_first < try_second)
	{
		cout << try_second << endl;
	}
	Fraction c;
	Fraction l(3.14, 7.62);
	cin >> c;
	cout << c << endl;
	if (l > c) 
	{
		cout << c << endl;
	}
	else if (l < c)
	{
		cout << l << endl;
	}
	

	
}
