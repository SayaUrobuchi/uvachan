#include <stdio.h>
#include <stdlib.h>

int ary[55];

int comp(const void *p, const void *q)
{
	return *(int*)q > *(int*)p ? 1 : -1;
}

int main()
{
	int count, n, i, j, k, ans;
	scanf("%d", &count);
	while(count--)
	{
		n = 0;
		while(scanf("%d", &ary[n]) == 1)
		{
			if(ary[n] == 0)
			{
				qsort(ary, n, sizeof(ary[0]), comp);
				for(i=0, ans=0; i<n&&ans<=5000000; i++)
				{
					for(j=0, k=2; j<=i&&k<=5000000; j++, k*=ary[i]);
					if(k > 5000000)
					{
						ans = 5000001;
						break;
					}
					ans += k;
				}
				if(ans > 5000000)
				{
					printf("Too expensive\n");
				}
				else
				{
					printf("%d\n", ans);
				}
				break;
			}
			n++;
		}
	}
	return 0;
}
