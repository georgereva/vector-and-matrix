#pragma once

#include <iostream>
using namespace std;
class vector
{
	unsigned line;
	double *arr;
public:
	vector();
	vector(unsigned n);
	vector(unsigned n,double a);
	vector(const vector &v);
	~vector();
	vector operator =(const vector v);
	double & operator [] (unsigned n);
	vector operator + ( vector &v)const;
	vector operator - ( vector &v)const;
	double operator * (vector &v)const;
	vector operator * (double c)const;
	friend vector operator * (double c,const vector &v);
	const vector & operator ++();
	void show()
	{
		if(line==0)
			cout<<"vector pustoi\n";
		for(unsigned i=0;i<line;++i)
			cout<<arr[i]<<' '<<' ';
		cout<<"\n";
		
	}
	int & Size_Vector();
	double Vector_El(int i);
};

class matrix
{
private:
	unsigned line;
	unsigned columns;
	double **arr;
public:
	matrix();
	matrix(unsigned);
	matrix(unsigned,unsigned);
	matrix(unsigned,unsigned,double);
	matrix(const matrix &); //конструктор копирования
	~matrix();
	
	friend ostream& operator << (ostream& os, const matrix&); //перегрузка оператора вывода для матриц
	friend istream& operator >> (istream& is, matrix&);       //перегрузка оператора ввода для матриц


	matrix operator =(const matrix&); //перегрузка оператора присваивания
	matrix operator +(const matrix&)const; //перегрузка оператора сложения
	matrix operator *(const matrix&)const; //перегрузка оператора умножения
    friend vector operator *(matrix&, vector&); //умножение матрицы на вектор
	friend vector operator *(vector &,matrix&); //умножение вектора на матрицу
	matrix operator *(double)const; //умножение на константу
	friend matrix operator *(double,const matrix&);
	int Size_columnsatr_line();
	int Size_columnsatr_columns();
	double columnsatr_El(unsigned n,unsigned m);

	void print()
	{
		cout << endl << endl;
		for(unsigned k=0;k<line;k++)
		{
			for(unsigned p=0;p<columns;p++)
			{
			cout<<arr[k][p]<<'\t';
			}
		cout<<endl;
		}
	}
};



