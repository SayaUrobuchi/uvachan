#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char target, n, path[21][21], reachable[21], rnum, check[21], ans[100], rcheck[21];
int count;

int comp(const void *p, const void *q)
{
	return (int)(*(char*)p - *(char*)q);
}

char checkpath(char now)
{
	char i;
	if(now == 1) return 1;
	for(i=1; i<n; i++)
	{
		if(path[now][i])
		{
			if(rcheck[i])
			{
				rcheck[i] = checkpath(i);
			}
			rcheck[now] += rcheck[i];
		}
	}
	if(rcheck[now] > -1)
	{
		reachable[rnum++] = now;
		return 1;
	}
	return 0;
}

void dfs(char now, char* str)
{
	char *i, *ptr, buf[4];
	if(now == target)
	{
		puts(ans);
		count++;
		return;
	}
	for(i=reachable; *i; i++)
	{
		ptr = &check[*i];
		if(*ptr && path[now][*i])
		{
			*ptr = 0;
			sprintf(buf, " %d", *i);
			strcpy(str, buf);
			dfs(*i, str + strlen(buf));
			*ptr = 1;
		}
	}
}

int main()
{
	int cas, in, in2;
	char i, j, k;
	cas = 0;
	memset(check, 1, sizeof(check));
	check[0] = 0;
	memset(ans, 32, sizeof(ans));
	ans[0] = 49;
	while(scanf("%d", &in) == 1)
	{
		target = in;
		memset(path, 0, sizeof(path));
		n = 0;
		while(scanf("%d%d", &in, &in2) == 2)
		{
			if(!(in + in2)) break;
			path[in][in2] = 1;
			path[in2][in] = 1;
			if(in > n) n = in;
			if(in2 > n) n = in2;
		}
		n++;
		memset(rcheck, -1, n);
		rcheck[1] = 1;
		rnum = 0;
		checkpath(target);
		qsort(reachable, rnum, 1, comp);
		reachable[rnum] = 0;
		printf("CASE %d:\n", ++cas);
		count = 0;
		dfs(1, ans + 1);
		printf("There are %d routes from the firestation to streetcorner %d.\n", count, target);
	}
	return 0;
}
