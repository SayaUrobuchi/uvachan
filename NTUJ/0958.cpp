#include <stdio.h>
#include <string.h>

int t1[1005], t2[1005], ary[20005];

int main()
{
	int count, n, m, i, j, p1, p2, d;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		memset(t1, 0, sizeof(t1));
		memset(t2, 0, sizeof(t2));
		for(i=0, j=n/2; i<j; i++)
		{
			t1[ary[i]]++;
		}
		for(j=n-n%1; i<j; i++)
		{
			t2[ary[i]]++;
		}
		for(i=n/2, j=n-n%1; i>=1; i--, j-=2)
		{
			for(p2=1; p2<=m; p2++)
			{
				if(t2[p2])
				{
					d = t2[p2];
					break;
				}
			}
			p1 = 1;
			while(p2<=m||d>0)
			{
				for(; p1<p2&&d>0; p1++)
				{
					d -= t1[p1];
				}
				if(d > 0)
				{
					break;
				}
				for(p2++; p2<=m&&d<=0; p2++)
				{
					d += t2[p2];
					if(d > 0)
					{
						break;
					}
				}
			}
			if(p2 > m && d == 0)
			{
				break;
			}
			t1[ary[i-1]]--;
			t2[ary[j-1]]--;
			t2[ary[j-2]]--;
			t2[ary[i-1]]++;
		}
		printf("%d\n", i);
	}
	return 0;
}
