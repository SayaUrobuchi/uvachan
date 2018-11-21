#include <stdio.h>
#include <string.h>

int n, m;
int used[15];
int tbl[15][30];
int own[30];
int ary[30][600];
int num[30];

int exchange(int now, int require)
{
	int i, j;
	if(tbl[now][require] > 1)
	{
		used[now] = 1;
		for(i=1; i<=m; i++)
		{
			if(!tbl[now][i] && own[i] > 1)
			{
				own[i]--;
				ary[i][num[i]++] = now;
				tbl[now][i] = 1;
				tbl[now][require]--;
				used[now] = 0;
				return 1;
			}
		}
		for(i=1; i<=m; i++)
		{
			if(!tbl[now][i] && num[i])
			{
				for(j=0; j<num[i]; j++)
				{
					if(!used[ary[i][j]] && exchange(ary[i][j], i))
					{
						ary[i][j] = now;
						used[now] = 0;
						tbl[now][i] = 1;
						tbl[now][require]--;
						return 1;
					}
				}
			}
		}
		used[now] = 0;
	}
	return 0;
}

int main()
{
	int cas, count, i, j, o, c;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(num, 0, sizeof(num));
		memset(own, 0, sizeof(own));
		memset(tbl, 0, sizeof(tbl));
		for(i=0; i<n; i++)
		{
			scanf("%d", &o);
			while(o--)
			{
				scanf("%d", &j);
				tbl[i][j]++;
				if(i)
				{
					ary[j][num[j]++] = i;
				}
				else
				{
					own[j]++;
				}
			}
		}
		for(i=1, c=0; i<=m; i++)
		{
			if(!own[i])
			{
				for(j=0; j<num[i]; j++)
				{
					if(exchange(ary[i][j], i))
					{
						c++;
						break;
					}
				}
			}
			else
			{
				c++;
			}
		}
		printf("Case #%d: %d\n", ++cas, c);
	}
	return 0;
}
