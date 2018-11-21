#include <stdio.h>

#define N 5005
#define NN (N*N+5)

int qn, qx[NN], qy[NN];
int used[N][N], dp[N][N];

int max(int p, int q)
{
	return p>q ? p : q;
}

int main()
{
	int n, i, j, xi, li, ans, cnt;
	cnt = 0;
	scanf("%d", &n);
	{
		++cnt;
		qn = 0;
		ans = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &xi, &li);
			for (j=0; j<qn; j++)
			{
				if (xi < qx[j])
				{
					if (used[xi][qy[j]] != cnt)
					{
						qx[qn] = xi;
						qy[qn] = qy[j];
						qn++;
						used[xi][qy[j]] = cnt;
					}
					dp[xi][qy[j]] = max(dp[xi][qy[j]], dp[qx[j]][qy[j]] + li);
					ans = max(ans, dp[xi][qy[j]]);
				}
				if (xi > qy[j])
				{
					if (used[qx[j]][xi] != cnt)
					{
						qx[qn] = qx[j];
						qy[qn] = xi;
						qn++;
						used[qx[j]][xi] = cnt;
					}
					dp[qx[j]][xi] = max(dp[qx[j]][xi], dp[qx[j]][qy[j]] + li);
					ans = max(ans, dp[qx[j]][xi]);
				}
			}
			if (used[xi][xi] != cnt)
			{
				qx[qn] = xi;
				qy[qn] = xi;
				qn++;
				used[xi][xi] = cnt;
			}
			dp[xi][xi] = max(dp[xi][xi], li);
			ans = max(ans, dp[xi][xi]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
