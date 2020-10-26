#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int idx[128];
string str[128];

bool comp(int p, int q)
{
	int i;
	for (i=0; i<n; i++)
	{
		if ((str[i][p] | 32) != (str[i][q] | 32))
		{
			return (str[i][p] | 32) < (str[i][q] | 32);
		}
	}
	return p < q;
}

int main()
{
	int i, j;
	bool first = true;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			cin >> str[i];
		}
		for (i=0; i<m; i++)
		{
			idx[i] = i;
		}
		sort(idx, idx+m, comp);
		if (!first)
		{
			cout << "\n";
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				cout << str[i][idx[j]];
			}
			cout << "\n";
		}
		first = false;
	}
	return 0;
}
