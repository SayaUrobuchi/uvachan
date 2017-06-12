#include <stdio.h>

int main()
{
	int count, a, b, c, d, e, f, g, res, t, cas;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
		res = a+b+c+d;
		t = e;
		if(f < t)
		{
			t = f;
		}
		if(g < t)
		{
			t = g;
		}
		res += (e+f+g-t)/2;
		if(res >= 90)
		{
			printf("Case %d: A\n", ++cas);
		}
		else if(res >= 80)
		{
			printf("Case %d: B\n", ++cas);
		}
		else if(res >= 70)
		{
			printf("Case %d: C\n", ++cas);
		}
		else if(res >= 60)
		{
			printf("Case %d: D\n", ++cas);
		}
		else
		{
			printf("Case %d: F\n", ++cas);
		}
	}
	return 0;
}
