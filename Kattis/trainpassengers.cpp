#include <iostream>
using namespace std;

int main()
{
	int n, m, i, t, a, b, c;
	bool gg;
	while (cin >> n >> m)
	{
		gg = false;
		for (i=0, t=0; i<m; i++)
		{
			cin >> a >> b >> c;
			t -= a;
			if (t < 0)
			{
				gg = true;
			}
			t += b;
			if (t > n)
			{
				gg = true;
			}
			if (t < n && c > 0)
			{
				gg = true;
			}
			if (i == m-1 && c != 0)
			{
				gg = true;
			}
		}
		if (t != 0)
		{
			gg = true;
		}
		if (gg)
		{
			cout << "impossible\n";
		}
		else
		{
			cout << "possible\n";
		}
	}
	return 0;
}
