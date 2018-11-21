#include <stdio.h>

int ary[100005];

int main()
{
	int count, n, i, p, q, t, c, mx, ans, cas;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		ary[0] = 0;
		for(i=1, mx=0; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			ary[i-1] = ary[i]-ary[i-1];
			if(ary[i-1] > mx)
			{
				mx = ary[i-1];
			}
		}
		for(p=mx, q=2147483647; p<=q; )
		{
			c = ((p+q)>>1);
			for(t=c, i=0; i<n; i++)
			{
				if(ary[i] > t)
				{
					break;
				}
				if(ary[i] == t)
				{
					t--;
				}
			}
			if(i < n)
			{
				p = c+1;
			}
			else
			{
				q = c-1;
				ans = c;
			}
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
