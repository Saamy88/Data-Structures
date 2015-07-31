#include <iostream>
using namespace std;

void F1(int n)
{
	if(n>=1 && n <= 8)
	{
		cout << n;
		F1(n-1);
	}
	else 
		cout << "*" ;
}

void F2(int n)
{
	if(n>=1 && n<=8)
	{
		F2(n-1);
		cout << n;
	}
	else
		cout << "*";
}

void F3(int n)
{
	if(n>=1 && n <= 8)
	{
		cout << n;
		F3(n + 1);
		cout << n;
	}
	else 
		cout << "*";
}
int main()
{
	F1(3);
	cout << endl;
	F1(7);
	cout << endl;
	F2(3);
	cout << endl;
	F2(7);
	cout << endl;
	F3(3);
	cout << endl;
	F3(7);
	cout << endl;
	return 0;
}