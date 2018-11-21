#include <stdio.h>

int main()
{
	int p, s, y, j, c, t;
	while(scanf("%d%d%d%d", &p, &s, &y, &j) == 4)
	{
		c = (j+12-s-y)/3;
		t = (j+12-s-y)%3;
		if(t > 0)
		{
			if(y-s != p)
			{
				if(t > 1)
				{
					y++;
				}
				s++;
			}
			else
			{
				if(t > 1)
				{
					s++;
				}
				y++;
			}
		}
		printf("%d %d %d\n", c+y, c+s, c);
	}
	return 0;
}
