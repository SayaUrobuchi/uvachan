#include <stdio.h>

#define M 3
#define N 256
#define N3 N*N*8

int cnt;
int used[N][N], inq[N][N], dis[N][N];
int qa[N3], qb[N3], qs[N3];
int w[M], now[M], nxt[M];

int gcd(int p, int q)
{
	if (q)
	{
		while ((p %= q) && (q %= p));
	}
	return p+q;
}

void push(int *idx, int a[M], int s)
{
	if (used[a[0]][a[1]] != cnt || dis[a[0]][a[1]] > s)
	{
		dis[a[0]][a[1]] = s;
		used[a[0]][a[1]] = cnt;
		if (inq[a[0]][a[1]] != cnt)
		{
			qa[*idx] = a[0];
			qb[*idx] = a[1];
			qs[*idx] = s;
			inq[a[0]][a[1]] = cnt;
			++(*idx);
		}
	}
}

int main()
{
	int count, d, dd, ans, i, j, k, l, p, ns, ts, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d%d", &w[0], &w[1], &w[2], &d);
		dd = 0;
		++cnt;
		qa[0] = 0;
		qb[0] = 0;
		inq[0][0] = cnt;
		dis[0][0] = 0;
		ans = 0;
		for (i=0, j=1; i<j; i++)
		{
			now[0] = qa[i];
			now[1] = qb[i];
			now[2] = w[2]-now[0]-now[1];
			ns = dis[now[0]][now[1]];
			inq[now[0]][now[1]] = 0;
			for (k=0; k<M; k++)
			{
				if (now[k] <= d)
				{
					if (now[k] > dd)
					{
						dd = now[k];
						ans = ns;
					}
					else if (now[k] == dd && ns < ans)
					{
						ans = ns;
					}
				}
			}
			for (k=0; k<M; k++)
			{
				if (now[k] != 0)
				{
					for (l=0; l<M; l++)
					{
						if (l != k && now[l] != w[l])
						{
							for (p=0; p<M; p++)
							{
								nxt[p] = now[p];
							}
							t = w[l] - now[l];
							if (t > now[k])
							{
								nxt[k] = 0;
								nxt[l] += now[k];
								ts = ns + now[k];
							}
							else
							{
								nxt[l] = w[l];
								nxt[k] -= t;
								ts = ns + t;
							}
							push(&j, nxt, ts);
						}
					}
				}
			}
		}
		printf("%d %d\n", ans, dd);
	}
	return 0;
}
