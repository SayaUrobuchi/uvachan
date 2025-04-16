#include <iostream>
using namespace std;

const int N = 200005;

int ary[N], recx[N], recy[N];
int tbl[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		ary[i] = i;
	}
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		recx[i] = ary[t];
		recy[i] = ary[t+1];
		swap(ary[t], ary[t+1]);
	}
	for (i=1; i<=n; i++)
	{
		tbl[ary[i]] = i;
	}
	for (i=0; i<m; i++)
	{
		int ans = tbl[1];
		if (recx[i] == 1)
		{
			ans = tbl[recy[i]];
		}
		else if (recy[i] == 1)
		{
			ans = tbl[recx[i]];
		}
		printf("%d\n", ans);
	}
	return 0;
}