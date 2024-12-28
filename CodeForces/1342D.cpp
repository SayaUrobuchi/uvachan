#include <stdio.h>
#include <vector>

const int N = 200005;

int tbl[N], lim[N];
std::vector<int> v[N];

int main()
{
	int n, m, i, j, p, q, t, mid, cnt;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		tbl[t]++;
	}
	for (i=1; i<=m; i++)
	{
		scanf("%d", &lim[i]);
	}
	cnt = 0;
	for (i=m; i>0; i--)
	{
		for (p=0, q=cnt-1, t=-1; p<=q; )
		{
			mid = ((p+q) >> 1);
			if (v[mid].size() < lim[i])
			{
				t = mid;
				q = mid-1;
			}
			else
			{
				p = mid+1;
			}
		}
		if (t == -1)
		{
			t = cnt;
		}
		for (j=t; tbl[i]; tbl[i]--)
		{
			v[j].emplace_back(i);
			if (v[j].size() == lim[i])
			{
				j++;
			}
		}
		if (v[j].size())
		{
			j++;
		}
		if (j > cnt)
		{
			cnt = j;
		}
	}
	printf("%d\n", cnt);
	for (i=0; i<cnt; i++)
	{
		printf("%d", v[i].size());
		for (j=0; j<v[i].size(); j++)
		{
			printf(" %d", v[i][j]);
		}
		puts("");
	}
	return 0;
}
