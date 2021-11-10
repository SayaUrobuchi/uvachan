#include <iostream>
using namespace std;

const int NN = (1<<22);

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ucnt;
int used[NN], par[NN], rnk[NN];

int enc(int a, int b)
{
	return (a<<11) | b;
}

int getpar(int cur)
{
	if (par[cur] == -1)
	{
		return cur;
	}
	return par[cur] = getpar(par[cur]);
}

void uni(int a, int b)
{
	int t, u;
	t = getpar(a);
	u = getpar(b);
	if (t != u)
	{
		if (rnk[t] > rnk[u])
		{
			swap(t, u);
		}
		par[t] = u;
		if (rnk[t] == rnk[u])
		{
			++rnk[u];
		}
	}
}

int main()
{
	int n, m, o, i, k, a, b, c, d, t, u, cmd;
	bool ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		++ucnt;
		scanf("%d", &o);
		for (i=0; i<o; i++)
		{
			scanf("%d", &cmd);
			if (cmd == 1)
			{
				scanf("%d%d", &a, &b);
				t = enc(a, b);
				par[t] = -1;
				rnk[t] = 1;
				used[t] = ucnt;
				for (k=0; k<4; k++)
				{
					c = a+dx[k];
					d = b+dy[k];
					if (c > 0 && c <= n && d > 0 && d <= m)
					{
						u = enc(c, d);
						if (used[u] == ucnt)
						{
							uni(t, u);
						}
					}
				}
			}
			else
			{
				scanf("%d%d%d%d", &a, &b, &c, &d);
				ans = false;
				t = enc(a, b);
				u = enc(c, d);
				if (used[t] == ucnt && used[u] == ucnt)
				{
					if (getpar(t) == getpar(u))
					{
						ans = true;
					}
				}
				//printf("ans: ");
				puts(ans?"Yes":"No");
			}
		}
	}
	return 0;
}
