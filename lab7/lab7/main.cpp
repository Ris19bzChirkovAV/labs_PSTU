#include "Vector.h"
#include <iostream>
#include "Time.h"

using namespace std;

void main()
{
	Time t;
	cin >> t;
	Vector<Time>A(5, t);
	cout << "Vvod 5 vector\n";
	cin >> A;
	cout << A << endl;
	Vector <Time>B(5, t);
	cout << B << endl;
	cout << "Copy\n";
	B = A;
	cout << B << endl;
	cout << "Dostup po index\n";
	cout << A[2] << endl;
	system("pause");
	cout << " Size = " << A() << endl;
	system("pause");
	int k;
	cout << "Vvedite const\n";
	cin >> k;
	cout << "+const\n";
	B += k;
	cout << B << endl;
}