#include <iostream>
using namespace std;

const int N = 1000005;

int par[N], rnk[N];

int getpar(int cur)
{
	if (par[cur] < 0)
	{
		return cur;
	}
	return par[cur] = getpar(par[cur]);
}

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		par[i] = -1;
	}
	for (i=0; i<m; i++)
	{
		char cmd;
		int a, b;
		scanf(" %c%d%d", &cmd, &a, &b);
		if (cmd == '?')
		{
			puts(getpar(a) == getpar(b) ? "yes" : "no");
		}
		else
		{
			a = getpar(a);
			b = getpar(b);
			if (a != b)
			{
				if (rnk[a] > rnk[b])
				{
					swap(a, b);
				}
				par[a] = b;
				if (rnk[a] == rnk[b])
				{
					++rnk[b];
				}
			}
		}
	}
	return 0;
}
