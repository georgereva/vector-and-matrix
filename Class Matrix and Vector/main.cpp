#include <iostream>
#include "matrix.h"
using namespace std;
int main()
{
	setlocale(LC_ALL,"Russian");

	
	matrix a(3,3,3);
	matrix b(3,3,5);
	matrix c(3,3);
	matrix d(3,3);
	matrix e(3,3);
	vector aa(3,2);
	vector ab(3);
	vector abc(3);
	double x(17.7);
	cout << "������� �";
	a.print();
	cout << endl;
	cout << "������� B";
	b.print();
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------";
	cout << endl;
	c = a + b;
	cout << "����� ������ A � B";
	c.print();
	d = a * b;
	cout << "\n������������ ������ A � B";
	d.print();
	e = b * x;
	cout << "\n������������ ������� B �� ��������� double(17.7)";
	e.print();
	cout << endl << endl;
	cout << "������ X" << endl << endl;;
	aa.show();
	ab = aa * a;
	cout << endl << "������������ ������� X �� ������� �" << endl << endl;
	ab.show();
	abc = b * aa;
	cout << endl << "������������ ������� B �� ������ X" << endl << endl;
	abc.show();
	cout << endl;
	
	
	system ("pause");
	return 0;
}