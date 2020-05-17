#include <iostream>
#include "Vector.h"

using namespace std;

void main()
{
	Vector a(5);
	cout << a << "\n";
	cout << "Vvedite a\n";
	cin >> a;
	cout << a << "\n";
	cout << "Dostup po index\n";
	a[2] = 100;
	cout << a << "\n";
	Vector b(5);
	cout << b << "\n";
	b = a;
	cout << b << "\n";
	Vector c(5);
	cout << "+ const\n";
	c = b + 100;
	cout << c << "\n";
	cout << "\n Lenth of a = " << a() << endl;
	cout << *(a.first()) << endl;
	Iterator i = a.first();
	i++;
	cout << *i << endl;
	cout << "Vivod with iterator\n";
	for (i = a.first(); i != a.last(); i++)
	{
		cout << *i << " ";
	}
}
