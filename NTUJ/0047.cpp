#include <stdio.h>

int r[16], g[16], b[16];

int getdis(int x, int y, int z)
{
	return x*x + y*y + z*z;
}

int main()
{
	int i, t, x, y, z, mindis, temp;
	for(i=0; i<16; i++)
	{
		scanf("%d%d%d", &r[i], &g[i], &b[i]);
	}
	while(scanf("%d%d%d", &x, &y, &z) == 3)
	{
		if(x == -1 && y == -1 && z == -1)
		{
			break;
		}
		for(i=0, mindis=2147483647; i<16; i++)
		{
			if((t=getdis(x-r[i], y-g[i], z-b[i])) < mindis)
			{
				mindis = t;
				temp = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", x, y, z, r[temp], g[temp], b[temp]);
	}
	return 0;
}
