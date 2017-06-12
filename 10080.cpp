#include <stdio.h>
#include <string.h>

int n, m, empty[100];
char path[100][100], check[100];
double gopher[100][2], hole[100][2];

double dis(int i, int j)
{
	double x, y;
	x = gopher[i][0] - hole[j][0];
	x *= x;
	y = gopher[i][1] - hole[j][1];
	y *= y;
	return x + y;
}

int checkpath(int now)
{
	int i;
	for(i=0; i<m; i++)
	{
		if(check[i] && path[now][i] == 1)
		{
			check[i] = 0;
			if(empty[i] == -1)
			{
				empty[i] = now;
				path[now][i] = 0;
				return 1;
			}
			else
			{
				if(checkpath(empty[i]))
				{
          path[now][i] = 0;
          path[empty[i]][i] = 1;
          empty[i] = now;
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int s, v, i, j, k, ans;
	while(scanf("%d%d%d%d", &n, &m, &s, &v) == 4)
	{
		for(i=0; i<n; i++) scanf("%lf%lf", &gopher[i][0], &gopher[i][1]);
		for(i=0; i<m; i++)
		{
			scanf("%lf%lf", &hole[i][0], &hole[i][1]);
			empty[i] = -1;
		}
		s *= v;
		s *= s;
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				path[i][j] = dis(i, j) > s ? -1 : 1;
			}
		}
		ans = 0;
		for(i=0; i<n; i++)
		{
			memset(check, 1, m);
			ans += checkpath(i);
		}
		printf("%d\n", n - ans);
	}
	return 0;
}
