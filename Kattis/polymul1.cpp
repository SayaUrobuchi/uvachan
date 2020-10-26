#include <iostream>
using namespace std;

long long a0[1024], a1[1024];

int main()
{
	int count, n, m, o, i, j;
	long long t;
	cin >> count;
	while (count--)
	{
		cin >> n;
		for (i=0; i<=n; i++)
		{
			cin >> a0[i];
		}
		cin >> m;
		for (i=0; i<=m; i++)
		{
			cin >> a1[i];
		}
		o = n+m;
		cout << o << "\n";
		cout << a0[0]*a1[0];
		for (i=1; i<=o; i++)
		{
			for (j=0, t=0; j<=i&&j<=n; j++)
			{
				if (i-j <= m)
				{
					t += a0[j] * a1[i-j];
				}
			}
			cout << " " << t;
		}
		cout << "\n";
	}
	return 0;
}
