#include <stdio.h>

int ans, sum[5000001], tbl[5000001], num[5000001], res[5000001];

int bisearch(int p, int q, int t)
{
	int c;
	if(p > q)
	{
		return ans;
	}
	c = ((p+q)>>1);
	if(res[c] >= t)
	{
		return bisearch(p, c-1, t);
	}
	ans = c;
	return bisearch(c+1, q, t);
}

int main()
{
	int count, n, i, j, k;
	num[2] = 1;
	sum[2] = 1;
	res[2] = 1;
	for(i=3; i<5000; )
	{
		if(tbl[i] == 0)
		{
			num[i] = 1;
			sum[i] = sum[i-1] + num[i];
			res[i] = res[i-1] + sum[i];
			for(j=i*i, k=i+i; j<=5000; j+=k)
			{
				tbl[j] = i;
			}
		}
		else
		{
			num[i] = num[i/tbl[i]] + 1;
			sum[i] = sum[i-1] + num[i];
			res[i] = res[i-1] + sum[i];
		}
		i++;
		num[i] = num[i/2] + 1;
		sum[i] = sum[i-1] + num[i];
		res[i] = res[i-1] + sum[i];
		i++;
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("%d\n", bisearch(1, 5000, n)+2);
	}
	return 0;
}
