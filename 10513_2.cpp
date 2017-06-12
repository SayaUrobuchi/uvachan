#include <stdio.h>
#include <string.h>

int n;
long long count;
int chk[26], rb[100];
int num[16];
int tbl[16][127];
char str[16][40000][16];
char list[16];
char s[16];

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

void dfs(int depth)
{
	int i;
	if(n == depth)
	{
		strcpy(str[n][num[n]++], list);
		return;
	}
	for(i=0; i<n; i++)
	{
		if(chk[i] || (depth > 1 && ab(list[depth-2]-65-i) == 1) || (depth && ab(list[depth-1]-65-i) == 2))
		{
		}
		else
		{
			if(rb[depth+i+n] || rb[depth-i+n])
			{
			}
			else
			{
				list[depth] = i + 65;  depth - k == i - list[k];
				rb[i+depth+n] = rb[depth-i+n] = 1;
				chk[i] = 1;
				dfs(depth+1);
				chk[i] = 0;
				rb[i+depth+n] = rb[depth-i+n] = 0;
			}
		}
	}
}

int main()
{
	int cas, i, j;
	cas = 0;
	for(i=1; i<16; i++)
	{
		list[i] = 0;
		n = i;
		dfs(0);
		printf("%d %d\n", i, num[i]);
	}
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(tbl, 0, sizeof(tbl));
		for(i=0, count=1; i<n; i++)
		{
			scanf("%s", s);
			if(s[0] == '?')
			{
				count *= n;
				tbl[i][0] = 1;
			}
			else
			{
				for(j=0; s[j]; j++)
				{
					tbl[i][s[j]] = 1;
				}
				count *= j;
			}
		}
		for(i=0; i<num[n]; i++)
		{
			for(j=0; j<n; j++)
			{
				if(!tbl[j][0] && !tbl[str[n][i][j]])
				{
					break;
				}
			}
			count -= (j == n);
		}
		printf("Case %d: %lld\n", ++cas, count);
	}
	return 0;
}
