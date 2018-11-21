#include <stdio.h>

int ary[100005];

int main()
{
	int n, i, j, p, q, min, sum;
	long long ans, temp;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for(i=0, ans=0; i<n; i++)
		{
			if(i == 0 || ary[i] > ary[i-1])
			{
				for(j=i, min=2147483647, sum=0; j<n; j++)
				{
					sum += ary[j];
					if(ary[j] < min)
					{
						min = ary[j];
					}
					if((temp=(long long)min*sum) > ans)
					{
						ans = temp;
						p = i;
						q = j;
					}
				}
			}
		}
		printf("%I64d\n%d %d\n", ans, p+1, q+1);
	}
	return 0;
}
