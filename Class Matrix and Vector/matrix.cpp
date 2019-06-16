#include "matrix.h"

#include "matrix.h"
vector::vector()
{
	line=0;
	arr=NULL;
}
vector::vector(unsigned n)
{
	line=n;
	arr=new double [line];
	for(unsigned i=0;i<line;++i)
		arr[i]=0;
}
vector::vector(unsigned n,double a)
{
	line=n;
	arr=new double[line];
	for(unsigned i=0;i<line;++i)
		arr[i]=a;
}
vector::vector(const vector &v)
{
	line=v.line;
	arr=new double [line];
	for(unsigned i=0;i<line;++i)
		arr[i]=v.arr[i];
}
vector::~vector()
{
	delete[]arr;
}

int & vector:: Size_Vector()
	{
		int n;
		n=line;
		return n;
	}
double vector::Vector_El(int i)
{
	double a;
	a=arr[i];
	return a;
}

double & vector:: operator[](unsigned n)
{
	return arr[n];
}
vector vector::operator+(vector &v)const
{
	vector a;
	if(line>v.line)
	{
		vector b(line);
		for(unsigned i=0;i<v.line;++i)
			b.arr[i]=v.arr[i];
		//b.show();
		a.line=line;
		a.arr=new double[a.line];
		for(unsigned k=0;k<line;++k)
		a.arr[k]=arr[k]+b.arr[k];
		//a.show();
	}
	else
	{
		vector b(v.line);
		for(unsigned i=0;i<line;++i)
			b.arr[i]=arr[i];
		//b.show();
		a.line=v.line;

		a.arr=new double[a.line];
		for(unsigned p=0;p<v.line;++p)
		a.arr[p]=v.arr[p]+b.arr[p];
		//a.show();

	}
	return a;
}
vector vector::operator -(vector &v)const
{
	vector a;
	if(line>v.line)
	{
		vector b(line);
		for(unsigned i=0;i<v.line;++i)
			b.arr[i]=v.arr[i];
		a.line=line;
		a.arr=new double [a.line];
		for(unsigned k=0;k<a.line;++k)
			a.arr[k]=arr[k]-b.arr[k];
	}
	else
	{
		vector b(v.line);
		for(unsigned i=0;i<line;++i)
			b.arr[i]=arr[i];
		a.line=v.line;
		a.arr=new double [a.line];
		for(unsigned k=0;k<a.line;++k)
			a.arr[k]=b.arr[k]-v.arr[k];
	}
	return a;
}
vector vector::operator =(const vector v)
{
	line=v.line;
	arr=new double [line];
	for(unsigned i=0;i<line;++i)
		arr[i]=v.arr[i];
	return *this;
}
vector vector::operator *(double c)const
{
	vector a=*this;
	for(unsigned i=0;i<line;++i)
		a.arr[i]=arr[i]*c;
	return a;
}
 vector operator *(double c,const vector &v)
{
	vector a(v.line);
	for(unsigned i=0;i<a.line;++i)
		a.arr[i]=c*v.arr[i];
	return a;
}
double vector::operator *(vector &v)const
 {
	 double s=0;
	 if(line<v.line)
	 {
		 vector b(line);
		 for(unsigned i=0;i<b.line;++i)
		 {
			 b.arr[i]=arr[i]*v.arr[i];
			 s=s+b.arr[i];
		 }
	 }
	 else
	 {
		 vector b(v.line);
		 for(unsigned p=0;p<b.line;++p)
		 {
			 b.arr[p]=arr[p]*v.arr[p];
			 s=s+b.arr[p];
		 }
	 }
	 return s;
 }
const vector &vector:: operator ++()
{
	vector a(line+1);
	for(unsigned i=0;i<line;++i)
	{
		a.arr[i]=arr[i];
	}
	line=a.line;
	arr=new double [line];
	for(unsigned i=0;i<line;++i)
	{
		arr[i]=a.arr[i];
	}
	return *this;
}





matrix::matrix():line(0),columns(0),arr(NULL){}
matrix::matrix(unsigned n)
{
	line = n;
	columns = n;
	arr=new double*[line];
	for(unsigned i=0;i<line;++i)
		arr[i]=new double[columns];
	for(unsigned k=0;k<line;k++)
		for(unsigned p=0;p<columns;p++)
			arr[k][p]=0;
}
matrix::matrix(unsigned n,unsigned m)
{
	line = n;
	columns = m;
	arr=new double*[line];
	for(unsigned i=0;i<line;++i)
		arr[i]=new double[columns];
	for(unsigned k=0;k<line;k++)
		for(unsigned p=0;p<columns;p++)
			arr[k][p]=0;
}
matrix::matrix(unsigned n,unsigned m,double a)
{
	line = n;
	columns = m;
	arr=new double*[line];
	for(unsigned i=0;i<line;++i)
		arr[i]=new double[columns];
	for(unsigned k=0;k<line;k++)
		for(unsigned p=0;p<columns;p++)
			arr[k][p]=a;
}
matrix::matrix(const matrix&b)
{
	line=b.line;
	columns=b.columns;
	arr=new double*[line];
	for(unsigned i=0;i<line;++i)
		arr[i]=new double[columns];
	for(unsigned k=0;k<line;++k)
		for(unsigned p=0;p<columns;++p)
			arr[k][p]=b.arr[k][p];
}
matrix::~matrix()
{
	for(unsigned k=0;k<line;++k)
		delete[]arr[k];
	delete[]arr;
}

 ostream& operator << (ostream& os, const matrix &m)
{
	for(unsigned i = 1; i < m.line + 1; i ++)
	{
		for(unsigned j = 1; j < m.columns + 1; j ++)
		{
			os << "  " << m.arr[i][j];
		}
	   cout << endl;
	}

	return os;
}

 istream& operator >> (istream& is, matrix& m)
 {
	
	m.arr	= new double *[m.line];
	for(unsigned i = 1; i < m.line + 1; i ++)
	{
		m.arr[i] = new double [m.columns];	 
		for(unsigned j = 1; j < m.columns + 1; j ++)
		{	cout<<"["<<i<<"]"<<"["<<j<<"]"<<" = ";
			is >> m.arr[i][j];
		}
	}
	system("cls");
	return is;
 }




matrix matrix:: operator+(const matrix&b)const
{
	if(line==b.line && columns==b.columns)
	{
		matrix c(line,columns);
		for(unsigned k=0;k<line;++k)
			for(unsigned p=0;p<columns;++p)
				c.arr[k][p]=arr[k][p]+b.arr[k][p];
		return c;
	}
	else
		cout<<"Error\n";
	return 0;
}
matrix matrix:: operator =(const matrix&b)
{
	line=b.line;
	columns=b.columns;
	arr=new double*[line];
	for(unsigned i=0;i<line;++i)
		arr[i]=new double[columns];
	for(unsigned k=0;k<line;++k)
		for(unsigned p=0;p<columns;++p)
			arr[k][p]=b.arr[k][p];
	return *this;
}
matrix matrix::operator *(const matrix &b)const
{
	double s;
	if(columns==b.line)
	{
		matrix c(line,b.columns);
		for(unsigned k=0;k<c.line;++k)
		{
			for(unsigned p=0;p<c.columns;++p)
			{
				s=0;
				for(unsigned i=0;i<columns;++i)
				{
					s+=arr[k][i]*b.arr[i][p];
				}
				c.arr[k][p]=s;
			}
		}
		return c;
	}
	else
		cout<<"Error\n";
	return 0;
}





int matrix::Size_columnsatr_line()
{
	int n;
	n=line;
	return n;
}
int matrix::Size_columnsatr_columns()
{
	int m;
	m=columns;
	return m;
}
double matrix::columnsatr_El(unsigned n,unsigned m)
{
	return arr[n][m];
}

vector  operator *(matrix&c ,vector &v)
{
	vector a;
	double s=0;
	int vn,mn,mm;
	mn=c.Size_columnsatr_line();
	mm=c.Size_columnsatr_columns();
	vn=v.Size_Vector();
	if(mm==vn)
	{
		vector b(mn);
		for(unsigned k=0;k<mn;++k)
		{ 
			s=0;
			//cout<<"s"<<s;
			for(unsigned p=0;p<mm;++p)
			{
				//cout<<"v[p]\t="<<v[p]<<endl;
				//cout<<"c[k][p]\t="<<c.columnsatr_El(k,p)<<endl;
				//cout<<"c[k][p]*v[p]\t="<<c.columnsatr_El(k,p)*v[p]<<endl;
				s+=v[p]*c.columnsatr_El(k,p);
				//cout<<"S=\t"<<s<<endl;
			}
			b[k]=s;
		}
		a=b;
		//return b;
	}
	return a;
}
 vector operator *(vector &v,matrix&c)
 {
	 vector a;
	 double s=0;
	 int vn,mn,mm;
	 mn=c.Size_columnsatr_line();
	 mm=c.Size_columnsatr_columns();
	 vn=v.Size_Vector();
	 if(vn==mn)
	 {
		 vector b(mm);
		 for(unsigned k=0;k<mm;++k)
		 { 
			 s=0;
			 for(unsigned p=0;p<mn;++p)
			 {
				 s+=v[p]*c.columnsatr_El(p,k);
				 //cout<<"S=\t"<<s;
			 }
			 b[k]=s;
		 }
		 a=b;
		//return b;
	}
	return a;
 }
matrix matrix::operator *(double c)const
{
	matrix b(line,columns);
	for(unsigned k=0;k<line;++k)
		for(unsigned p=0;p<columns;++p)
			b.arr[k][p]=arr[k][p]*c;
	return b;
}
matrix operator *(double c,const matrix & B)
{
	matrix b(B.line,B.columns);
	for(unsigned k=0;k<b.line;++k)
		for(unsigned p=0;p<b.columns;++p)
			b.arr[k][p]=B.arr[k][p]*c;
	return b;
}










				





		

	

