/*
	ID: sa072682
	LANG: C
	TASK: camelot
*/
#include <stdio.h>

int queuer[1100], queuec[1100], step[1100], map[41][27], dis[1100][41][27], chk[41][27], used[41][27];
int wayr[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int wayc[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int walkr[9] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
int walkc[9] = {0, 1, -1, 1, -1, 0, 1, -1, 0};

int valid(int x, int y, int lx, int ly)
{
	return x > 0 && x <= lx && y > 0 && y <= ly;
}

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, m, i, j, k, l, p, q, c, r, d, s, tr, tc, kc, kr, ans;
	char ch[2];
	freopen("camelot.in", "r", stdin);
	freopen("camelot.out", "w", stdout);
	scanf("%d%d%s%d", &n, &m, ch, &kr);
	kc = ch[0] - 64;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			for(k=0; k<1100; k++)
			{
				dis[k][i][j] = 1000000000;
			}
		}
	}
	i = 1;
	while(scanf("%s%d", ch, &queuer[0]) == 2)
	{
		queuec[0] = ch[0] - 64;
		chk[queuer[0]][queuec[0]] = i;
		step[0] = 0;
		for(p=0, q=1; p<q; p++)
		{
			r = queuer[p];
			c = queuec[p];
			s = step[p] + 1;
			map[r][c] += step[p];
			used[r][c] = 1;
			dis[i][r][c] = step[p];
			for(k=0; k<8; k++)
			{
				tr = r + wayr[k];
				tc = c + wayc[k];
				if(valid(tr, tc, n, m) && chk[tr][tc] != i)
				{
					chk[tr][tc] = i;
					queuer[q] = tr;
					queuec[q] = tc;
					step[q++] = s;
				}
			}
		}
		i++;
	}
	for(j=0; j<9; j++)
	{
		queuec[0] = kc + walkc[j];
		queuer[0] = kr + walkr[j];
		if(valid(queuec[0], queuer[0], m, n))
		{
			step[0] = 0;
			chk[queuer[0]][queuec[0]] = i+j;
			for(p=0, q=1; p<q; p++)
			{
				r = queuer[p];
				c = queuec[p];
				s = step[p] + 1;
				dis[i+j][r][c] = step[p];
				for(k=0; k<8; k++)
				{
					tr = r + wayr[k];
					tc = c + wayc[k];
					if(valid(tr, tc, n, m) && chk[tr][tc] != i+j)
					{
						chk[tr][tc] = i+j;
						queuer[q] = tr;
						queuec[q] = tc;
						step[q++] = s;
					}
				}
			}
		}
	}
	l = i;
	for(i=1, ans=2147483647; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			if((used[i][j] && map[i][j] < ans) || l == 1)
			{
				d = min(dis[l][i][j], ab(i-kr)+ab(j-kc));
				for(k=1; k<l&&d; k++)
				{
					if(d > dis[k][kr][kc] + dis[l][i][j] - dis[k][i][j])
					{
						d = dis[k][kr][kc] + dis[l][i][j] - dis[k][i][j];
					}
				}
				if(map[i][j] + d < ans)
				{
					ans = map[i][j] + d;
				}
				for(p=1; p<9; p++)
				{
					if(valid(kr+walkr[p], kc+walkc[p], n, m))
					{
						d = dis[l+p][i][j] + 1;
						for(k=1; k<l&&d; k++)
						{
							if(d > dis[k][kr+walkr[p]][kc+walkc[p]] + dis[l+p][i][j] + 1 - dis[k][i][j])
							{
								d = dis[k][kr+walkr[p]][kc+walkc[p]] + dis[l+p][i][j] + 1 - dis[k][i][j];
							}
						}
						if(map[i][j] + d < ans)
						{
							ans = map[i][j] + d;
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}
