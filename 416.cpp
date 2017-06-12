#include <stdio.h>
#include <string.h>

int failed[8];
char tbl[10][8] = {"YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY"};
char ary[10][8];

int dfs(int now, int depth)
{
	int i, record[8];
	/*printf("%d %d\n", now, depth);*/
	if(depth == -1 || now == -1)
	{
		return 1;
	}
	memset(record, 0, sizeof(record));
	for(i=0; i<7; i++)
	{
		if((failed[i] || tbl[now][i] == 'N') && ary[depth][i] == 'Y')
		{
			break;
		}
		if(!failed[i] && tbl[now][i] == 'Y' && ary[depth][i] == 'N')
		{
			record[i] = 1;
		}
	}
	if(i == 7)
	{
		for(i=0; i<7; i++)
		{
			if(record[i])
			{
				failed[i] = 1;
			}
		}
		if(dfs(now-1, depth-1))
		{
			return 1;
		}
		for(i=0; i<7; i++)
		{
			if(record[i])
			{
				failed[i] = 0;
			}
		}
	}
	return 0;
}

int main()
{
	int n, i;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", ary[n-i-1]);
		}
		for(i=9; i>=n-1; i--)
		{
			memset(failed, 0, sizeof(failed));
			if(dfs(i, n-1))
			{
				break;
			}
		}
		if(i >= n-1)
		{
			printf("MATCH\n");
		}
		else
		{
			printf("MISMATCH\n");
		}
	}
	return 0;
}
