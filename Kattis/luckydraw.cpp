#include <iostream>
#include <cmath>

const int T = 1024;

double c[T+1][T+1];

int main()
{
	int n, m, i, j;
	double r, sum, ans, now;
	c[0][0] = 1;
	for (i=1; i<=T; i++)
	{
		c[i][0] = 1;
		for (j=1; j<=i; j++)
		{
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
	while (scanf("%d%d%lf", &n, &m, &r) == 3)
	{
		for (i=m, sum=0, ans=0; i<=T; i++, sum+=now)
		{
			now = c[i-1][m-1] * pow(1-r, m) * pow(r, i-m);
			for (j=2; j<=n; j++)
			{
				ans += c[n][j] * pow(now, j) * pow(sum, n-j);
			}
			//printf(".... %.10lf\n", sum);
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
