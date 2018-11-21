#include <stdio.h>

int x[101], y[101];
int dp[1001][1001];

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int gcd(int p, int q)
{
	if(dp[p+500][q+500])
	{
		return dp[p+500][q+500];
	}
	if(!p || !q)
	{
		return dp[p+500][q+500]=1;
	}
	if(p % q)
	{
		return dp[p+500][q+500]=gcd(q, p%q);
	}
	return dp[p+500][q+500]=q;
}

int cross(int x1, int y1, int x2, int y2)
{
	return x1*y2 - x2*y1;
}

int main()
{
	int n, m, i, j, k, tx, ty, left, right, temp;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0, m=n+n; i<m; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
		}
		for(i=-500; i<=500; i++)
		{
			for(j=-500; j<=500; j++)
			{
				if((i || j) && gcd(ab(i), ab(j)) == 1)
				{
					tx = j;
					ty = -i;
					for(k=0, left=right=0; k<m; k++)
					{
						temp = cross(tx, ty, x[k], y[k]);
						if(!temp)
						{
							break;
						}
						else if(temp < 0)
						{
							left++;
						}
						else
						{
							right++;
						}
					}
					if(left == right && left == n)
					{
						printf("%d %d\n", i, j);
						break;
					}
				}
			}
			if(j <= 500)
			{
				break;
			}
		}
	}
	return 0;
}
