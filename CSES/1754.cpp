#include <iostream>
using namespace std;

int main()
{
	int count, a, b;
	cin >> count;
	while (count--)
	{
		cin >> a >> b;
		if ((a<<1) < b || (b<<1) < a || (a+b)%3)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
	return 0;
}

