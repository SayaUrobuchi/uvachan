#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, ans, maxteam;
int ary[20];
int used[20];

int comp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

int dfs(int people, int team, int last, int value)
{
	int i;
	if(people == 3)
	{
		people = 0;
		team++;
		last = 0;
		value = 0;
	}
	if(team > ans)
	{
		ans = team;
		if(ans == maxteam)
		{
			return 1;
		}
	}
	for(i=last; i<n; i++)
	{
		if(!used[i])
		{
			used[i] = 1;
			if(people == 0)
			{
				if(dfs(1, team, i+1, ary[i]))
				{
					return 1;
				}
				used[i] = 0;
				return 0;
			}
			else if(people == 1)
			{
				if(dfs(2, team, i+1, value+ary[i]))
				{
					return 1;
				}
			}
			else
			{
				if(value+ary[i] >= 20)
				{
					if(dfs(3, team, i+1, value+ary[i]))
					{
						return 1;
					}
				}
				else
				{
					used[i] = 0;
					return 0;
				}
			}
			used[i] = 0;
		}
	}
	return 0;
}

int main()
{
	int cas, i;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		maxteam = n / 3;
		ans = 0;
		if(maxteam)
		{
			qsort(ary, n, sizeof(int), comp);
			memset(used, 0, sizeof(used));
			dfs(0, 0, 0, 0);
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
