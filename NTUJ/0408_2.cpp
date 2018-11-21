#include <stdio.h>
#include <string.h>

int list[65536], step[65536], num[20], map[15][15], dp1[4096], dp2[4096];

int main()
{
	int n, m, i, j, k, l, s, ans, *p, *q, *tmp;
	list[0] = 0;
	step[0] = 0;
	for(i=0, j=1; i<j; i++)
	{
		num[step[i]] = i;
		if(step[i] == 13)
		{
			break;
		}
		list[j] = list[i];
		step[j++] = step[i] + 1;
		if(!i || (list[i] & (1<<step[i]-1)) == 0)
		{
			list[j] = list[i] + (1<<step[i]);
			step[j++] = step[i] + 1;
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		memset(dp1, 0, sizeof(dp1));
		p = dp1;
		q = dp2;
		for(i=num[m-1]+1, l=num[m]; i<=l; i++)
		{
			s = list[i];
			for(k=0; k<m; k++)
			{
				if((s & (1<<k)) && map[0][k] == 0)
				{
					break;
				}
			}
			if(k < m)
			{
				continue;
			}
			p[s] = 1;
		}
		for(i=1; i<n; i++)
		{
			for(j=num[m-1]+1; j<=l; j++)
			{
				q[s=list[j]] = 0;
				for(k=0; k<m; k++)
				{
					if((s & (1<<k)) && map[i][k] == 0)
					{
						break;
					}
				}
				if(k < m)
				{
					continue;
				}
				for(k=num[m-1]+1; k<=l; k++)
				{
					if((s & list[k]) == 0)
					{
						q[s] += p[list[k]];
						if(q[s] >= 100000000)
						{
							q[s] -= 100000000;
						}
					}
				}
			}
			tmp = p;
			p = q;
			q = tmp;
		}
		for(i=num[m-1]+1, ans=0; i<=num[m]; i++)
		{
			ans += p[list[i]];
			if(ans >= 100000000)
			{
				ans -= 100000000;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
