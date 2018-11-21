#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TOP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int ans, tt2, tnum;
int list[12], cnt[12], hash[128];
char str[12][5];

int comp(const void *p, const void *q)
{
	return strcmp((char*)p, (char*)q);
}

void dfs(int dep)
{
	int i, top, left;
	if(dep == 12)
	{
		ans++;
		return;
	}
	top = (dep>=3?str[list[dep-3]][DOWN]:tt2);
	left = (dep%3?str[list[dep-1]][RIGHT]:tt2);
	for(i=0; i<tnum; i++)
	{
		if(cnt[i] && (top & str[i][TOP]) && (left & str[i][LEFT]))
		{
			cnt[i]--;
			list[dep] = i;
			dfs(dep+1);
			cnt[i]++;
		}
	}
}

int main()
{
	int cas, count, i, j;
	cas = 0;
	hash['R'] = 1;
	hash['G'] = 2;
	hash['B'] = 3;
	tt2 = (1<<4) - 1;
	scanf("%d", &count);
	while(count--)
	{
		for(i=0; i<12; i++)
		{
			scanf("%s", str[i]);
			for(j=0; j<4; j++)
			{
				str[i][j] = (1<<hash[str[i][j]]);
			}
		}
		qsort(str, 12, sizeof(str[0]), comp);
		for(i=0, tnum=0; i<12; )
		{
			for(j=i+1; j<12; j++)
			{
				if(strcmp(str[i], str[j]))
				{
					break;
				}
			}
			if(i != tnum)
			{
				strcpy(str[tnum], str[i]);
			}
			cnt[tnum] = j - i;
			tnum++;
			i = j;
		}
		ans = 0;
		dfs(0);
		if(ans)
		{
			for(i=0; i<tnum; i++)
			{
				for(j=2; j<=cnt[i]; j++)
				{
					ans *= j;
				}
			}
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
