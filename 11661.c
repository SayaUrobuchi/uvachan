#include <stdio.h>

char str[10000001];

int main()
{
	int n, i, r, t, ans;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		scanf("%s", str);
		for(i=0, r=-10000000, t=-10000000, ans=10000000; i<n; i++)
		{
			if(str[i] == 'Z')
			{
				ans = 0;
				break;
			}
			else if(str[i] == 'R')
			{
				r = i;
				if(r-t < ans)
				{
					ans = r-t;
				}
			}
			else if(str[i] == 'D')
			{
				t = i;
				if(t-r < ans)
				{
					ans = t-r;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
