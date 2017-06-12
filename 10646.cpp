#include <stdio.h>

char s[52][3];

int main()
{
	int cas, count, i, j, x, y, a;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		for(i=51; i>=0; i--)
		{
			scanf("%s", s[i]);
		}
		y = 0;
		x = 25;
		for(i=0; i<3; i++)
		{
			if(sscanf(s[x], "%d", &a) != 1)
			{
				a = 10;
			}
			y += a;
			x += 10-a+1;
		}
		j = 52-y;
		if(j <= x)
		{
			j -= (x-25);
		}
		printf("Case %d: %s\n", ++cas, s[j]);
	}
	return 0;
}
