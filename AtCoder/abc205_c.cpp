#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a < 0 && !(c&1))
		{
			a = -a;
		}
		if (b < 0 && !(c&1))
		{
			b = -b;
		}
		if (a < b)
		{
			cout << "<\n";
		}
		else if (a == b)
		{
			cout << "=\n";
		}
		else
		{
			cout << ">\n";
		}
	}
	return 0;
}
