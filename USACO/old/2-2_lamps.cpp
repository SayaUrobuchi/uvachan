/*
	ID: sa072682
	LANG: C
	TASK: lamps
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[101], ans[16][101], tbl[101], tbl2[101], num;
int ary[16], n, c;

int comp(const void *p, const void *q)
{
	return strcmp((char*)p, (char*)q);
}

void change(char* s, int type)
{
	int i;
	if(!type)
	{
		for(i=0; i<n; i++)
		{
			s[i] = 97 - s[i];
		}
	}
	else if(type == 1)
	{
		for(i=0; i<n; i+=2)
		{
			s[i] = 97 - s[i];
		}
	}
	else if(type == 2)
	{
		for(i=1; i<n; i+=2)
		{
			s[i] = 97 - s[i];
		}
	}
	else
	{
		for(i=0; i<n; i+=3)
		{
			s[i] = 97 - s[i];
		}
	}
}

void dfs(char* s, int depth, int press)
{
	int i;
	char buf[101];
	strcpy(buf, s);
	if(depth == 4)
	{
		if(press <= c && !((c-press)%2))
		{
			for(i=0; i<n; i++)
			{
				if(tbl[i] && buf[i] == 48)
				{
					break;
				}
				if(tbl2[i] && buf[i] == 49)
				{
					break;
				}
			}
			if(i == n)
			{
				strcpy(ans[num++], buf);
			}
		}
		return;
	}
	dfs(buf, depth+1, press);
	change(buf, depth);
	dfs(buf, depth+1, press+1);
}

int main()
{
	int m, i, j;
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
	scanf("%d%d", &n, &c);
	while(scanf("%d", &m) == 1)
	{
		if(m == -1)
		{
			break;
		}
		tbl[m-1] = 1;
	}
	while(scanf("%d", &m) == 1)
	{
		if(m == -1)
		{
			break;
		}
		tbl2[m-1] = 1;
	}
	num = 0;
	memset(str, 49, sizeof(str));
	str[n] = 0;
	dfs(str, 0, 0);
	if(num)
	{
		qsort(ans, num, sizeof(ans[0]), comp);
		for(i=0; i<num; i++)
		{
			printf("%s\n", ans[i]);
		}
	}
	else
	{
		printf("IMPOSSIBLE\n");
	}
	scanf(" ");
	return 0;
}
