#include <stdio.h>
#include <string.h>

int ary1[20][20], ary2[20][20], tbl1[501], tbl2[601], width[501];
char str1[501][21], str2[601][21], list[22];

void dfs1(int depth, int w, int value)
{
	value += ary1[depth][w];
	if(!depth)
	{
		if(!tbl1[value])
		{
			strcpy(str1[value], list+1);
			width[value] = w;
		}
		else
		{
			if(width[value] > w)
			{
				width[value] = w;
				strcpy(str1[value], list+1);
			}
			else if(width[value] == w && strcmp(str1[value], list+1) > 0)
			{
				strcpy(str1[value], list+1);
			}
		}
		tbl1[value]++;
		return;
	}
	list[depth] = 'R';
	dfs1(depth-1, w, value);
	list[depth] = 'L';
	dfs1(depth-1, w+1, value);
}

void dfs2(int depth, int w, int value, int n)
{
	value += ary2[depth][w];
	if(depth == n-1)
	{
		if(!tbl2[value])
		{
			strcpy(str2[value], list);
		}
		tbl2[value]++;
		return;
	}
	list[depth] = 'L';
	dfs2(depth+1, w, value, n);
	list[depth] = 'R';
	dfs2(depth+1, w+1, value, n);
}

int main()
{
	int n, s, i, j, w, ans;
	long long c;
	while(scanf("%d%d", &n, &s) == 2)
	{
		if(!n && !s)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<n-i; j++)
			{
				scanf("%d", &ary1[i][j]);
			}
		}
		ary2[0][0] = ary1[n-1][0];
		for(i=1; i<n; i++)
		{
			for(j=0; j<=i; j++)
			{
				scanf("%d", &ary2[i][j]);
			}
		}
		memset(tbl1, 0, sizeof(tbl1));
		memset(tbl2, 0, sizeof(tbl2));
		list[n] = 0;
		dfs1(n-1, 0, 0);
		list[n-1] = 0;
		dfs2(0, 0, 0, n);
		for(i=0, c=0, w=100; i<=s; i++)
		{
			if(tbl1[i] && tbl2[s-i+ary2[0][0]])
			{
				c += (long long)tbl1[i] * (long long)tbl2[s-i+ary2[0][0]];
				if(width[i] < w)
				{
					w = width[i];
					ans = i;
				}
				else if(width[i] == w)
				{
					if(strcmp(str1[ans], str1[i]) > 0)
					{
						ans = i;
					}
				}
			}
		}
		printf("%lld\n", c);
		if(c)
		{
			/*printf("XDDD%d Length %d %d\n", ans, strlen(str1[ans]), strlen(str2[s-ans+ary2[0][0]]));*/
			printf("%d %s%s\n", width[ans], str1[ans], str2[s-ans+ary2[0][0]]);
		}
		else
		{
			printf("\n");
		}
	}
	return 0;
}
