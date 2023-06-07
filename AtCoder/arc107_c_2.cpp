#include <iostream>
using namespace std;

const int N = 64;
const int N2 = N * N;
const int M = 998244353;

int n, cc, ans, ucnt;
int used[N];
long long row[N], col[N], rb[N], cb[N];
int px[N2], py[N2];

void dfs(long long ary[], int cur)
{
	ans = ((long long)ans * ++cc) % M;
	used[cur] = ucnt;
	for (int i=0; i<n; i++)
	{
		if (used[i] != ucnt && !(ary[cur] & (1LL << i)))
		{
			dfs(ary, i);
		}
	}
}

int main()
{
	int m, n2, i, j, t;
	scanf("%d%d", &n, &m);
	n2 = n * n;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf("%d", &t);
			px[t] = i;
			py[t] = j;
		}
	}
	for (i=1, j=n2; i<=n2; i++)
	{
		for (; j>=1&&j+i>m; j--)
		{
			cb[py[j]] |= (1LL << px[j]);
		}
		row[px[i]] |= cb[py[i]];
	}
	for (i=1, j=n2; i<=n2; i++)
	{
		for (; j>=1&&j+i>m; j--)
		{
			rb[px[j]] |= (1LL << py[j]);
		}
		col[py[i]] |= rb[px[i]];
	}
	long long *lis[] = {row, col};
	for (j=0, ans=1; j<2; j++)
	{
		++ucnt;
		for (i=0; i<n; i++)
		{
			if (used[i] != ucnt)
			{
				cc = 0;
				dfs(lis[j], i);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
