#include <stdio.h>

int main()
{
	int count, n, i, p, q, t, c, mx, ans, cas;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		ans = 0;
		for(i=1, mx=0, q=0; i<=n; i++)
		{
			scanf("%d", &p);
			if(p-q > ans)
			{
				ans = p-q;
				mx = ans-1;
			}
			else if(p-q > mx)
			{
				mx = ++ans;
			}
			else if(p-q == mx)
			{
				mx--;
			}
			q = p;
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
