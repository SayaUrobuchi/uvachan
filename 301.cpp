#include <stdio.h>
#include <string.h>

int n, m, o, ans;
int start[32], end[32], people[32], price[32], tbl[18];

void dfs(int last, int stops, int earning, int passenger)
{
	int i;
	/*printf("stops: %d, earn: %d\n", stops, earning);*/
	if(stops == m)
	{
		if(earning > ans)
		{
			ans = earning;
		}
		return;
	}
	if(!last)
	{
		passenger -= tbl[stops];
	}
	dfs(0, stops+1, earning, passenger);
	for(i=last; i<o; i++)
	{
		if(start[i] == stops)
		{
			/*printf("%d %d %d\n", passenger, people[i], n);*/
			if(passenger + people[i] <= n)
			{
				tbl[end[i]] += people[i];
				dfs(i+1, stops, earning+price[i], passenger+people[i]);
				tbl[end[i]] -= people[i];
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
		}
		ans = 0;
		memset(tbl, 0, sizeof(tbl));
		dfs(0, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
