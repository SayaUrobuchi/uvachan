#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m, o, ans;
int start[32], end[32], people[32], price[32], tbl[18], index[32];

int comp(const void *p, const void *q)
{
	return start[*(int*)p] - start[*(int*)q];
}

void dfs(int last, int stops, int earning, int passenger, int flag)
{
	int i, j;
	/*printf("stops: %d, earn: %d\n", stops, earning);*/
	if(stops == m)
	{
		if(earning > ans)
		{
			ans = earning;
		}
		return;
	}
	if(flag)
	{
		passenger -= tbl[stops];
	}
	dfs(last, stops+1, earning, passenger, 1);
	for(i=last; i<o; i++)
	{
		j = index[i];
		if(start[j] > stops)
		{
			return;
		}
		if(start[j] == stops)
		{
			/*printf("%d %d %d\n", passenger, people[i], n);*/
			if(passenger + people[j] <= n)
			{
				tbl[end[j]] += people[j];
				dfs(i+1, stops, earning+price[j], passenger+people[j], 0);
				tbl[end[j]] -= people[j];
			}
		}
	}
}

int main()
{
	int i;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(!n && !m && !o)
		{
			break;
		}
		for(i=0; i<o; i++)
		{
			scanf("%d%d%d", &start[i], &end[i], &people[i]);
			price[i] = (end[i] - start[i]) * people[i];
			index[i] = i;
		}
		qsort(index, o, sizeof(int), comp);
		ans = 0;
		memset(tbl, 0, sizeof(tbl));
		dfs(0, 0, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
