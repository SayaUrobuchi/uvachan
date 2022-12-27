#include <iostream>
#include <cstring>
using namespace std;

int ary[1048576], par[262144], rnk[262144];

int getpar(int now)
{
	if (par[now] == -1)
	{
		return now;
	}
	return par[now] = getpar(par[now]);
}

int main()
{
	int n, i, j, a, b, ans;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
		}
		memset(par, -1, sizeof(par));
		memset(rnk, -1, sizeof(rnk));
		for (i=0, j=n-1, ans=0; i<j; i++, j--)
		{
			a = getpar(ary[i]);
			b = getpar(ary[j]);
			if (a != b)
			{
				++ans;
				if (rnk[a] < rnk[b])
				{
					swap(a, b);
				}
				par[a] = b;
				if (rnk[a] == rnk[b])
				{
					--rnk[b];
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
