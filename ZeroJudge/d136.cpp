#include <stdio.h>

unsigned long long ary1[1000005];

int main()
{
	int n, m, i, j, ans;
	unsigned long long k;
	while(scanf("%d%d", &m, &n) == 2)
	{
		while(m--)
		{
			for(i=0; i<n; i++)
			{
				scanf("%llu", &ary1[i]);
			}
			for(i=0, j=0, ans=0; i<n; i++)
			{
				scanf("%llu", &k);
				for(; j<n&&ary1[j]<k; j++);
				if(ary1[j] == k)
				{
					ans++;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
