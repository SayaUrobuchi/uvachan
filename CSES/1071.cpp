#include <iostream>
using namespace std;

int main()
{
	int count, a, b;
	long long c, t;
	cin >> count;
	while (count--)
	{
		cin >> a >> b;
		c = max(a, b) - 1;
		t = c * c;
		if (c & 1)
		{
			swap(a, b);
		}
		if (b <= a)
		{
			t += b;
		}
		else
		{
			t += b + b - a;
		}
		cout << t << "\n";
	}
	return 0;
}

