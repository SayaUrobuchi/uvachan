#include <stdio.h>
#include <string.h>

int ss, tt;
int used[1005], q[1005], st[1005], pp[1005], map[1005][1005], mapp[1005][1005];
int px[10005], py[10005];

int bfs()
{
	int i, j, k, nn, ns, nex;
	memset(used, 0, sizeof(used));
	q[0] = ss;
	st[0] = 0;
	used[ss] = 0;
	for(i=0, j=1; i<j; i++)
	{
		nn = q[i];
		ns = st[i] + 1;
		for(k=0; k<pp[nn]; k++)
		{
			nex = map[nn][k];
			if(nex == tt)
			{
				return ns;
			}
			if(used[nex] == 0)
			{
				used[nex] = 1;
				q[j] = nex;
				st[j] = ns;
				j++;
			}
		}
	}
	return 2147483647;
}

int main()
{
	int n, m, i, j, res, rd, temp;
	while(scanf("%d", &m) == 1)
	{
		if(m == 0)
		{
			break;
		}
		scanf("%d%d", &ss, &tt);
		scanf("%d", &n);
		memset(pp, 0, sizeof(pp));
		for(i=1; i<=n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			map[px[i]][pp[px[i]]++] = py[i];
		}
		if(ss == tt)
		{
			printf("0 0\n");
			continue;
		}
		res = bfs();
		rd = 0;
		memset(mapp, 0, sizeof(mapp));
		for(i=1; i<=n; i++)
		{
			memset(pp, 0, sizeof(pp));
			for(j=1; j<=n; j++)
			{
				if(i == j)
				{
					if(mapp[py[j]][px[j]] != i)
					{
						map[py[j]][pp[py[j]]++] = px[j];
						mapp[py[j]][px[j]] = i;
					}
				}
				else
				{
					if(mapp[px[j]][py[j]] != i)
					{
						map[px[j]][pp[px[j]]++] = py[j];
						mapp[px[j]][py[j]] = i;
					}
				}
			}
			temp = bfs();
			if(temp < res)
			{
				res = temp;
				rd = i;
			}
		}
		printf("%d %d\n", res, rd);
	}
	return 0;
}
