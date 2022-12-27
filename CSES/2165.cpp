#include <iostream>
using namespace std;

void rec(int st, int ed, int td, int n)
{
	if (n > 1)
	{
		rec(st, td, ed, n-1);
	}
	cout << st << " " << ed << "\n";
	if (n > 1)
	{
		rec(td, ed, st, n-1);
	}
}

int main()
{
	int n, i, t;
	while (cin >> n)
	{
		for (i=0, t=1; i<n; i++)
		{
			t <<= 1;
		}
		cout << t-1 << "\n";
		rec(1, 3, 2, n);
	}
	return 0;
}

