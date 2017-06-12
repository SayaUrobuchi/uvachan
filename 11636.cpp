#include <stdio.h>
#include <math.h>

int main()
{
	int cas, n, p, q, c, ans;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(n < 0)
		{
			break;
		}
		if(n == 1)
		{
			printf("Case %d: %d\n", ++cas, 0);
			continue;
		}
		printf("Case %d: %d\n", ++cas, (int)(log2(n-1)+1));
		/*ans = 0;
		for(p=0, q=20; p<=q; )
		{
			c = ((p+q)>>1);
			if((1<<c) >= n)
			{
				ans = c;
				q = c-1;
			}
			else
			{
				p = c+1;
			}
		}
		printf("Case %d: %d\n", ++cas, ans);*/
	}
	return 0;
}
