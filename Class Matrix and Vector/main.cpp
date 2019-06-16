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
	cout << "Матрица А";
	a.print();
	cout << endl;
	cout << "Матрица B";
	b.print();
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------";
	cout << endl;
	c = a + b;
	cout << "Сумма матриц A и B";
	c.print();
	d = a * b;
	cout << "\nПроизведение матриц A и B";
	d.print();
	e = b * x;
	cout << "\nПроизведение матрицы B на константу double(17.7)";
	e.print();
	cout << endl << endl;
	cout << "Вектор X" << endl << endl;;
	aa.show();
	ab = aa * a;
	cout << endl << "Произведение Вектора X на Матрицу А" << endl << endl;
	ab.show();
	abc = b * aa;
	cout << endl << "Произведение Матрицы B на вектор X" << endl << endl;
	abc.show();
	cout << endl;
	
	
	system ("pause");
	return 0;
}