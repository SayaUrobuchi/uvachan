#include <stdio.h>
#include <string.h>
#include <vector>

std::vector<int> v[1024];

int dir[1024], px[1024], py[1024], pr[1024];

int gcd(int p, int q)
{
	while ((p %= q) && (q %= p));
	return p+q;
}

int check(int x, int y, int d)
{
	return x*x + y*y == d*d;
}

int dfs(int cur, int d)
{
	int i, nxt;
	dir[cur] = d;
	for (i=0; i<v[cur].size(); i++)
	{
		nxt = v[cur][i];
		if (!dir[nxt])
		{
			if (!dfs(nxt, 3-d))
			{
				return 0;
			}
		}
		else if (dir[nxt] != 3-d)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n, i, j, t;
	while (scanf("%d", &n) == 1)
	{
		memset(dir, 0, sizeof(dir));
		for (i=0; i<n; i++)
		{
			v[i].clear();
		}
		for (i=0; i<n; i++)
		{
			scanf("%d%d%d", &px[i], &py[i], &pr[i]);
			for (j=0; j<i; j++)
			{
				if (check(px[i]-px[j], py[i]-py[j], pr[i]+pr[j]))
				{
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		if (!dfs(0, 1))
		{
			puts("-1");
		}
		else if (!dir[n-1])
		{
			puts("0");
		}
		else
		{
			t = gcd(pr[0], pr[n-1]);
			printf("%d %s%d\n", pr[n-1]/t, dir[0]==dir[n-1]?"":"-", pr[0]/t);
		}
	}
	return 0;
}
