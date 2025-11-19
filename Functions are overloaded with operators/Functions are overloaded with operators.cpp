#include<iostream>
#include<iomanip>
using namespace std;
class P
{
	int num;
	int x;
	friend P& operator++(P&);
	friend P operator++(P&, int);
public:
	P(int a = 0, int x = 0)
	{
		num = a;
		this->x = x;
	}
	P(P& a)
	{
		num = a.num;
		x = a.x;
	}
	void show()
	{
		cout << "num=  " << num << "   x=  " << x << endl;
	}
	friend ostream& operator<<(ostream& out, P& b);
};
ostream& operator<<(ostream& out, P& b)
{
	out << "num=  " << b.num << "   x=  " << b.x << endl;
	return out;
}
P& operator++(P&b)
{
	b.num++;
	b.x++;
	return b;
}
P operator++(P&a, int)
{
	P temp(a);
	a.num++; a.x++;
	return temp;
}
void test01()
{
	P z(12, 12);
	z++;
	z.show();
	cout << z << endl;
}
void test02()
{
	P c(15, 16);
	++c;
	c.show();
	cout << c << endl;
}
int main()
{
	test01();
	test02();
	return 0;
}