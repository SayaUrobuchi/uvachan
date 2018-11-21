#include <stdio.h>
#include <string.h>

int n, m;
int num[10001];
int ary[10001][45];
int sused[45];
int tused[10001];
int tbl[45][10001];
int arrive[45];
int deadline[45];
int need[45];

int fill(int);

int assign(int now, int target)
{
	int i;
	if(num[now] < m)
	{
		ary[now][num[now]++] = target;
		return 1;
	}
	else
	{
		for(i=0; i<num[now]; i++)
		{
			if(!sused[ary[now][i]] && fill(ary[now][i]))
			{
				tbl[ary[now][i]][i] = 0;
				ary[now][i] = target;
				return 1;
			}
		}
	}
	return 0;
}

int fill(int now)
{
	int i;
	sused[now] = 1;
	for(i=arrive[now]; i<deadline[now]; i++)
	{
		if(!tbl[now][i] && !tused[i])
		{
			tused[i] = 1;
			if(assign(i, now))
			{
				tbl[now][i] = 1;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int count, i;
	scanf("%d", &count);
	while(count--)
	{
		memset(num, 0, sizeof(num));
		memset(tbl, 0, sizeof(tbl));
		scanf("%d%d", &m, &n);
		for(i=1; i<=n; i++)
		{
			scanf("%d%d%d", &arrive[i], &need[i], &deadline[i]);
		}
		for(i=1; i<=n; i++)
		{
			for(; need[i]; need[i]--)
			{
				memset(sused, 0, sizeof(sused));
				memset(tused, 0, sizeof(tused));
				if(!fill(i))
				{
					break;
				}
			}
			if(need[i])
			{
				break;
			}
		}
		if(i > n)
		{
			printf("FEASIBLE\n");
		}
		else
		{
			printf("NO WAY\n");
		}
	}
	return 0;
}
