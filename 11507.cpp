#include <stdio.h>

char ary[100005][5];

int main()
{
	int m, d, x, y, z, i, n;
	char *buf;
	while(scanf("%d", &m) == 1)
	{
		if(m == 0)
		{
			break;
		}
		x = y = z = 0;
		d = 0;
		n = m;
		while(--m)
		{
			scanf("%s", ary[m]);
		}
		for(i=0; i<n; i++)
		{
			buf = ary[i];
			if(*buf == 'N')
			{
				continue;
			}
			if(*(buf+1) == 'y')
			{
				if(d != 1)
				{
					d = 1;
					if(*buf == '+')
					{
						y = 0;
					}
					else
					{
						y = 1;
					}
				}
				else
				{
					d = 0;
					if(y)
					{
						x = 0;
					}
					else
					{
						x = 1;
					}
				}
			}
			if(*(buf+1) == 'z')
			{
				if(d != 2)
				{
					d = 2;
					if(*buf == '+')
					{
						z = 0;
					}
					else
					{
						z = 1;
					}
				}
				else
				{
					d = 0;
					if(z)
					{
						x = 0;
					}
					else
					{
						x = 1;
					}
				}
			}
		}
		if(d == 0)
		{
			if(x)
			{
				printf("-x\n");
			}
			else
			{
				printf("+x\n");
			}
		}
		else if(d == 1)
		{
			if(y)
			{
				printf("-y\n");
			}
			else
			{
				printf("+y\n");
			}
		}
		else
		{
			if(z)
			{
				printf("-z\n");
			}
			else
			{
				printf("+z\n");
			}
		}
	}
	return 0;
}
