#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	int best, ans, ans_x, ans_y, ans_ite;
	for (i=1, best=1e9; i<=m; i++)
	{
		int ite;
		long long l, r;
		for (l=1, r=(long long)n*m, ite=0; l!=r; ite++)
		{
			long long nl = (long long)(i-1)*n + ((l-1)/m+1);
			long long nr = (long long)(i-1)*n + ((r-1)/m+1);
			if (nl == l && nr == r)
			{
				break;
			}
			l = nl;
			r = nr;
		}
		if (l == r)
		{
			int x = (l-1) / m + 1;
			int y = (l-1) % m + 1;
			int dx = min(abs(x-(((n-1)>>1)+1)), 
						 abs(x-((n>>1)+1)));
			int dy = min(abs(y-(((m-1)>>1)+1)), 
						 abs(y-((m>>1)+1)));
			if (dx + dy < best)
			{
				best = dx + dy;
				ans = i;
				ans_x = x;
				ans_y = y;
				ans_ite = ite;
			}
		}
	}
	printf("%d %d %d %d\n", ans, ans_x, ans_y, ans_ite);
	return 0;
}
