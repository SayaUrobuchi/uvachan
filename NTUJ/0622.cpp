#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int acnt, n, m;
int id[25], dis[25], pnum[25], map[25][25], used[25][1048576];
int pp[1048576], alis[1048576][25], lis[25];
char buf[1000005];
long long ans;
long long dp[25][1048576];

int comp(const void *p, const void *q)
{
	int i;
	for(i=0; i<m; i++)
	{
		if(alis[*(int*)p][i] != alis[*(int*)q][i])
		{
			return alis[*(int*)p][i] - alis[*(int*)q][i];
		}
	}
	return 0;
}

int icomp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int find(int tar)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(id[i] == tar)
		{
			return i;
		}
	}
	return -1;
}

int calc(int stat, int head, int dep)
{
	int i, tar;
	long long temp, mx;
	if(used[head][stat])
	{
		return dp[head][stat];
	}
	used[head][stat] = 1;
	dp[head][stat] = (long long)dis[head] * dep;
	if(dep == m)
	{
		return dp[head][stat];
	}
	for(i=0, mx=-1; i<pnum[head]; i++)
	{
		tar = map[head][i];
		if(stat & (1<<tar))
		{
			temp = calc(stat-(1<<tar), tar, dep+1);
			if(temp > mx)
			{
				mx = temp;
			}
		}
	}
	return dp[head][stat]+=mx;
}

void trace(int stat, int head, int dep)
{
	int i, tar;
	long long temp;
	lis[dep] = id[head];
	if(dep == m-1)
	{
		for(i=0; i<m; i++)
		{
			alis[acnt][i] = lis[i];
		}
		pp[acnt] = acnt;
		acnt++;
		return;
	}
	for(i=0; i<pnum[head]; i++)
	{
		tar = map[head][i];
		if(stat & (1<<tar))
		{
			temp = calc(stat-(1<<tar), tar, dep+1);
			if(temp + (long long)dis[head]*(dep+1) == dp[head][stat])
			{
				trace(stat-(1<<tar), tar, dep+1);
			}
		}
	}
}

int main()
{
	int i, j, tar;
	char *ptr;
	while(gets(buf))
	{
		sscanf(buf, "%d", &m);
		if(m == 0)
		{
			break;
		}
		gets(buf);
		n = 0;
		ptr = strtok(buf, " ");
		if(ptr)
		{
			do
			{
				id[n] = atoi(ptr);
				ptr = strtok(NULL, " ");
				dis[n] = atoi(ptr);
				n++;
			}while(ptr=strtok(NULL, " "));
		}
		gets(buf);
		memset(pnum, 0, sizeof(pnum));
		ptr = strtok(buf, " ");
		if(ptr)
		{
			do
			{
				if(ptr[strlen(ptr)-1] == ':')
				{
					sscanf(ptr, "%d", &tar);
					tar = find(tar);
				}
				else
				{
					map[tar][pnum[tar]++] = find(atoi(ptr));
				}
			}while(ptr=strtok(NULL, " "));
		}
		memset(used, 0, sizeof(used));
		for(i=0, ans=0.0.0; i<n; i++)
		{
			if(calc(((1<<n)-1)-(1<<i), i, 1) > ans)
			{
				ans = calc(((i<<n)-1)-(1<<i), i, 1);
			}
		}
		for(i=0, acnt=0; i<n; i++)
		{
			if(calc(((1<<n)-1)-(1<<i), i, 1) == ans)
			{
				trace(((1<<n)-1)-(1<<i), i, 0);
			}
		}
		printf("%d %lld\n", acnt, ans);
		qsort(pp, acnt, sizeof(int), comp);
		for(i=0; i<acnt; i++)
		{
			printf("%d", alis[pp[i]][0]);
			for(j=1; j<m; j++)
			{
				printf(" %d", alis[pp[i]][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
