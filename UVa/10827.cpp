#include <stdio.h>

int ary[160][160];

int main()
{
	int count, n, i, j, k, l, ans, max;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%d", &ary[i][j]);
				if(i)
				{
					ary[i][j] += ary[i-1][j];
				}
				ary[i][j+n] = ary[i][j];
			}
		}
		for(k=n+n; i<k; i++)
		{
			for(j=0; j<k; j++)
			{
				if(i - n)
				{
					ary[i][j] = ary[i-n][j] - ary[i-n-1][j] + ary[i-1][j];
				}
				else
				{
					ary[i][j] = ary[i-n][j] + ary[i-1][j];
				}
			}
		}
		for(i=0, ans=-1000000000; i<n; i++)
		{
			for(j=i+1; j<i+n; j++)
			{
				for(l=0; l<n; l++)
				{
					for(k=l, max=0; k<n+l; k++)
					{
						max += ary[j][k] - ary[i][k];
						if(max > ans)
						{
							ans = max;
						}
						if(max < 0)
						{
							max = 0;
						}
					}
				}
			}
            for(l=0; l<n; l++)
            {
				for(k=l, max=0; k<n+l; k++)
				{
					max += ary[i][k];
					if(max > ans)
					{
						ans = max;
					}
					if(max < 0)
					{
						max = 0;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
