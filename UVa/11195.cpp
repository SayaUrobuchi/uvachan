#include <stdio.h>
#include <string.h>

int next[15], list[15], ans[190000][15], count, num;
char map[14][15], chk[35], chk2[35];

void dfs(int depth, int n)
{
	int i, j, a1, a2;
	if(depth == n)
	{
		for(i=0, a1=1, a2=(list[0]!=n/2+1); i<n; i++)
		{
			if(map[i][list[i]-1] == '*')
			{
				a1 = 0;
			}
			if(map[i][n-list[i]] == '*')
			{
				a2 = 0;
			}
		}
		count += a1 + a2;
		return;
	}
	for(i=0; j=next[i]; i=j)
	{
		if(chk[j+depth] && chk2[j-depth+14])
		{
			chk[j+depth] = chk2[j-depth+14] = 0;
			list[depth] = j;
			next[i] = next[j];
			dfs(depth+1, n);
			next[i] = j;
			chk[j+depth] = chk2[j-depth+14] = 1;
		}
	}
}

void dfs2(int depth, int n)
{
	int i, j, a1, a2;
	if(depth == n)
	{
		for(i=0; i<n; i++)
		{
			ans[num][i] = list[i];
		}
		num++;
		return;
	}
	for(i=0; j=next[i]; i=j)
	{
		if(chk[j+depth] && chk2[j-depth+14])
		{
			chk[j+depth] = chk2[j-depth+14] = 0;
			list[depth] = j;
			next[i] = next[j];
			dfs2(depth+1, n);
			next[i] = j;
			chk[j+depth] = chk2[j-depth+14] = 1;
		}
	}
}

int main()
{
	int cas, n, i, j, a1, a2;
	cas = 0;
	n = 14;
	num = 0;
	for(i=0; i<n; i++)
	{
		next[i] = i + 1;
	}
	next[i] = count = 0;
	for(i=0; i<n/2; i++)
	{
		memset(chk, 1, sizeof(chk));
		memset(chk2, 1, sizeof(chk2));
		next[i] = next[i+1];
		list[0] = i + 1;
		chk[i+1] = chk2[i+15] = 0;
		dfs2(1, n);
		next[i] = i + 1;
	}
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
			next[i] = i + 1;
		}
		if(n == 14)
		{
			for(j=0, count=0; j<num; j++)
			{
				for(i=0, a1=1, a2=1; i<n; i++)
				{
					if(map[i][ans[j][i]-1] == '*')
					{
						a1 = 0;
					}
					if(map[i][n-ans[j][i]] == '*')
					{
						a2 = 0;
					}
				}
				count += a1 + a2;
			}
			printf("Case %d: %d\n", ++cas, count);
			continue;
		}
		next[i] = count = 0;
		for(i=0; i<n/2; i++)
		{
			memset(chk, 1, sizeof(chk));
			memset(chk2, 1, sizeof(chk2));
			next[i] = next[i+1];
			list[0] = i + 1;
			chk[i+1] = chk2[i+15] = 0;
			dfs(1, n);
			next[i] = i + 1;
		}
		if(n % 2)
		{
			memset(chk, 1, sizeof(chk));
			memset(chk2, 1, sizeof(chk2));
			next[i] = next[i+1];
			list[0] = i + 1;
			chk[i+1] = chk2[i+15] = 0;
			dfs(1, n);
			next[i] = i + 1;
		}
		printf("Case %d: %d\n", ++cas, count);
	}
	return 0;
}
