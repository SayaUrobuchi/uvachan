#include <stdio.h>

int main()
{
	int n, i, p, t, c, ans, temp;
	while(scanf("%d%d%d", &p, &t, &n) == 3)
	{
		for(i=0, c=0; i<n; i++)
		{
			scanf("%d", &temp);
			c += temp;
		}
		temp = t / 5;
		ans = -p * t * 3 / 10;
		if(c < temp)
		{
			ans += c * p * 7 / 10;
		}
		else
		{
			ans += temp * p * 7 / 10;
			if(c < t * 4 / 10)
			{
				ans += (c-temp) * p * 8 / 10;
			}
			else
			{
				ans += (t * 4 / 10 - temp) * p * 8 / 10;
				temp = t * 4 / 10;
				if(c < t * 6 / 10)
				{
					ans += (c-temp) * p * 9 / 10;
				}
				else
				{
					ans += (t * 6 / 10 - temp) * p * 9 / 10;
					temp = t * 6 / 10;
					if(c > temp)
					{
						ans += (c - temp) * p;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
