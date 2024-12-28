#include <stdio.h>

int main()
{
	int n, a, b, i, t;
	while(scanf("%d", &n) == 1)
	{
		while(scanf("%d", &a)!=1);
		for(i=1, t=1; i<n; i++)
		{
			while(scanf("%d", &b)!=1);
			if(t && b!=a)
			{
				t = 0;
			}
		}
		printf(t?"Yes\n":"No\n");
	}
	return 0;
}
