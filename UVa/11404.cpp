#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pptr;
int dp[1001][1001], used[1001][1001];
char *pal[1001][1001];
char *pool[1000001];
char buf[1001];
char str[1001];

int min(int p, int q)
{
	return p < q ? p : q;
}

char *get_pool(char *s)
{
	if(pool[pptr])
	{
		free(pool[pptr]);
	}
	pool[pptr] = (char*)malloc(strlen(s)+1);
	strcpy(pool[pptr], s);
	pptr++;
	return pool[pptr-1];
}

int calc(int p, int q)
{
	if(used[p][q])
	{
		return dp[p][q];
	}
	used[p][q] = 1;
	if(p > q)
	{
		pal[p][q] = "";
		return 0;
	}
	if(p == q)
	{
		dp[p][q] = 0;
		sprintf(buf, "%c", str[p]);
		pal[p][q] = get_pool(buf);
		return dp[p][q];
	}
	if(str[p] == str[q])
	{
		dp[p][q] = calc(p+1, q-1);
		sprintf(buf, "%c%s%c", str[p], pal[p+1][q-1], str[p]);
		pal[p][q] = get_pool(buf);
		return dp[p][q];
	}
	dp[p][q] = min(calc(p+1, q), calc(p, q-1)) + 1;
	if(dp[p+1][q] == dp[p][q-1])
	{
		if(strcmp(pal[p+1][q], pal[p][q-1]) > 0)
		{
			pal[p][q] = pal[p][q-1];
		}
		else
		{
			pal[p][q] = pal[p+1][q];
		}
	}
	else
	{
		if(dp[p+1][q] > dp[p][q-1])
		{
			pal[p][q] = pal[p][q-1];
		}
		else
		{
			pal[p][q] = pal[p+1][q];
		}
	}
	return dp[p][q];
}

int main()
{
	int len;
	while(gets(str))
	{
		len = strlen(str);
		memset(used, 0, sizeof(used));
		pptr = 0;
		calc(0, len-1);
		printf("%s\n", pal[0][len-1]);
	}
	return 0;
}
