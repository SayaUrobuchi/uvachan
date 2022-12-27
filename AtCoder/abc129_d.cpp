#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char buf[2048];
vector<int> ptr, row[2048], col[2048];

int main()
{
	int n, m, i, j, k, ans;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		col[i].emplace_back(-1);
	}
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		row[i].emplace_back(-1);
		for (j=0; j<m; j++)
		{
			if (buf[j] == '#')
			{
				row[i].emplace_back(j);
				col[j].emplace_back(i);
			}
		}
		row[i].emplace_back(m);
	}
	for (i=0; i<m; i++)
	{
		col[i].emplace_back(n);
	}
	ptr.resize(m, 1);
	for (i=0, ans=0; i<n; i++)
	{
		for (j=0, k=1; j<m; j++)
		{
			if (row[i][k] <= j)
			{
				++k;
				++ptr[j];
			}
			if (row[i][k-1] != j)
			{
				ans = max(ans, row[i][k]-row[i][k-1]-1 + col[j][ptr[j]]-col[j][ptr[j]-1]-1 - 1);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}