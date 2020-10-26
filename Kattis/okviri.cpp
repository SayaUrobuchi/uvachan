#include <iostream>
using namespace std;

string s;

void f()
{
	int i, j;
	string t;
	t.resize(1+s.size()*4, '.');
	for (i=2, j=1; i<t.size(); i+=4, j++)
	{
		t[i] = (j%3 ? '#' : '*');
	}
	cout << t << "\n";
}

void g()
{
	int i, j;
	string t;
	t.resize(1+s.size()*4, '.');
	for (i=2, j=1; i<t.size(); i+=4, j++)
	{
		t[i-1] = t[i+1] = (j%3 ? '#' : '*');
	}
	cout << t << "\n";
}

void h()
{
	int i, j;
	string t;
	t.resize(1+s.size()*4, '.');
	for (i=2, j=1; i<t.size(); i+=4, j++)
	{
		t[i] = s[j-1];
		t[i-2] = t[i+2] = (j%3 ? '#' : '*');
	}
	for (i=12; i<t.size(); i+=12)
	{
		t[i] = '*';
	}
	cout << t << "\n";
}

int main()
{
	while (getline(cin, s))
	{
		f();
		g();
		h();
		g();
		f();
	}
	return 0;
}
