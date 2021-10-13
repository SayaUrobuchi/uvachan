#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, i, cmd, t, u;
	int a[4], b[4];
	string s;
	while (cin >> n)
	{
		a[1] = a[2] = 1;
		b[1] = b[2] = 0;
		for (i=0; i<n; i++)
		{
			cin >> cmd;
			if (cmd == 1)
			{
				cin >> t;
				cout << max(a[1]*t+b[1], a[2]*t+b[2]) << "\n";
			}
			else if (cmd == 2)
			{
				cin >> t >> s >> u;
				if (s[0] == '+')
				{
					b[t] += u;
				}
				else
				{
					a[t] *= u;
					b[t] *= u;
				}
			}
			else
			{
				t = a[1]-a[2];
				u = b[2]-b[1];
				if (t == 0 || u % t)
				{
					cout << "no\n";
				}
				else
				{
					cout << u/t << "\n";
				}
			}
		}
	}
	return 0;
}
