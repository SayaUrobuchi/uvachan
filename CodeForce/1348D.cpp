#include <stdio.h>
#include <algorithm>

int ary[128];

int main()
{
	int count, n, i, j, diff, m;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		ary[0] = 1;
		for (i=1; (1<<i)-1<n; i++)
		{
			ary[i] = (1<<i);
		}
		diff = (1<<i)-1-n;
		for (j=i-1; diff&&j>0; j--)
		{
			m = (j+1 < i ? (ary[j+1]+1)/2 : ary[j-1]);
			if (ary[j-1] > m)
			{
				m = ary[j-1];
			}
			if (m < ary[j])
			{
				if (ary[j]-m > diff)
				{
					ary[j] -= diff;
					diff = 0;
				}
				else
				{
					ary[j] -= m;
					diff -= m;
				}
			}
		}
		printf("%d\n%d", i-1, ary[1]-ary[0]);
		for (j=2; j<i; j++)
		{
			printf(" %d", ary[j]-ary[j-1]);
		}
		puts("");
	}
	return 0;
}
