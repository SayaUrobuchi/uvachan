#include <stdio.h>

int main()
{
	int n, x, y, z, dir, i;
	char buf[20];
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		x = y = z = 0;
		dir = 0;
		for(i=1; i<n; i++)
		{
			scanf("%s", buf);
			if(*buf != 'N')
			{
				if(*(buf+1) == 'y')
				{
					if(dir == 0)
					{
						dir = 1;
						y = (*buf=='+' ? (x) : (x+1)) % 2;
					}
					else if(dir == 1)
					{
						dir = 0;
						x = (*buf=='+' ? (y+1) : (y)) % 2;
					}
				}
				else
				{
					if(dir == 0)
					{
						dir = 2;
						z = (*buf=='+' ? (x) : (x+1)) % 2;
					}
					else if(dir == 2)
					{
						dir = 0;
						x = (*buf=='+' ? (z+1) : (z)) % 2;
					}
				}
			}
		}
		if(dir == 0)
		{
			printf(x ? "-x\n" : "+x\n");
		}
		else if(dir == 1)
		{
			printf(y ? "-y\n" : "+y\n");
		}
		else if(dir == 2)
		{
			printf(z ? "-z\n" : "+z\n");
		}
	}
	return 0;
}

