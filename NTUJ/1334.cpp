#include <stdio.h>

int used[305][305][305][2], dp[305][305][305][2];

int recurs(int w, int h, int k, int cut)
{
	int *res;
	int i, j;
	if(h > ((k+2)>>1))
	{
		h = ((k+2)>>1);
	}
	if(used[w][h][k][cut])
	{
		return dp[w][h][k][cut];
	}
	used[w][h][k][cut] = 1;
	res = &dp[w][h][k][cut];
	if(h == 0)
	{
		return *res = 0;
	}
	if(w < k)
	{
		return *res = 0;
	}
	if(k == 1)
	{
		return *res = 1;
	}
	if(cut)
	{
		for(i=1; i<w; i++)
		{
			for(j=k-w+i; j<k&&j<=i; j++)
			{
				*res = ((long long)recurs(i, h, j, 1) * recurs(w-i, h, k-j, 0) + *res) % 1000000007;
			}
		}
	}
	if(h > 1)
	{
		for(i=1; i<w; i++)
		{
			for(j=1; j+i+k-1<=w; j++)
			{
				*res = (*res+recurs(w-j-i, h-1, k-1, 0)) % 1000000007;
			}
		}
	}
	return *res;
}

int main()
{
	int count, n, m, k, i, res;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &k);
		res = recurs(n, m, k, 1);
		for(i=1; i<=k; i++)
		{
			res = (long long)res*i % 1000000007;
		}
		printf("%d\n", res);
	}
	return 0;
}
