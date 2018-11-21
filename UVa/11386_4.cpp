#include <stdio.h>
#include <stdlib.h>

int ary[5010];
int c[5010];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int n, i, j, k;
	unsigned int temp;
	long long ans;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary, n, sizeof(int), comp);
		for(i=0, k=0; i<n; i=j, k++)
		{
			for(j=i+1; j<n; j++)
			{
				if(ary[j] != ary[i])
				{
					break;
				}
			}
			ary[k] = ary[i];
			c[k] = j - i;
		}
		n = k;
		for(i=0, ans=0; i<n; i++)
		{
			for(j=i, k=i+1; j<n&&k<n; )
			{
				if((temp=(unsigned int)ary[i] + ary[j]) == ary[k])
				{
					if(i == j)
					{
						ans += c[i] * (c[i]-1) / 2 * c[k];
					}
					else
					{
						ans += c[i] * c[j] * c[k];
					}
					j++;
					k++;
				}
				else if(temp > ary[k])
				{
					k++;
				}
				else
				{
					j++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
