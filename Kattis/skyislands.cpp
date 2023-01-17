#include <iostream>
using namespace std;

const int N = 1005;

int par[N], cnt[N], rnk[N];

int getpar(int cur)
{
	if (par[cur] == -1)
	{
		return cur;
	}
	return par[cur] = getpar(par[cur]);
}

void merge(int a, int b)
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
		cnt[b] += cnt[a];
		if (rnk[a] == rnk[b])
		{
			++rnk[b];
		}
	}
}

int main()
{
	int n, m, i, a, b;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		par[i] = -1;
		rnk[i] = 1;
		cnt[i] = 1;
	}
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		merge(a, b);
	}
	puts(cnt[getpar(1)]==n?"YES":"NO");
	return 0;
}
