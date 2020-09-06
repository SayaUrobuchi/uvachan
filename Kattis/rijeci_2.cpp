#include <iostream>
using namespace std;

int main()
{
	int n, a, b, i, next_a, next_b;
	while (cin >> n)
	{
		a = 1;
		b = 0;
		for (i=0; i<n; i++)
		{
			// a => b provides 0a and 1b
			// b => ba provides 1a and 1b
			next_a = a*0 + b*1;
			next_b = a*1 + b*1;
			a = next_a;
			b = next_b;
		}
		cout << a << " " << b << "\n";
	}
	return 0;
}
