#include <stdio.h>

int f;
char map[200][200], tbl[128];

int recursion(int lx, int ly, int rx, int ry)
{
	int i, j, cx, cy;
	for(i=lx; i<=rx; i++)
	{
		for(j=ly; j<=ry; j++)
		{
			if(map[i][j] != map[lx][ly])
			{
				break;
			}
		}
		if(j <= ry)
		{
			break;
		}
	}
	if(f)
	{
		printf(" ");
	}
	f = 1;
	if(i <= rx)
	{
		printf("g");
		cx = lx + rx;
		cx >>= 1;
		cy = ly + ry;
		cy >>= 1;
		recursion(lx, cy+1, cx, ry);
		recursion(lx, ly, cx, cy);
		recursion(cx+1, ly, rx, cy);
		recursion(cx+1, cy+1, rx, ry);
	}
	else
	{
		printf("%c", tbl[map[lx][ly]]);
	}
}

int main()
{
	int n, i;
	tbl['0'] = 'w';
	tbl['1'] = 'b';
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		f = 0;
		recursion(0, 0, n-1, n-1);
		printf("\n");
	}
	return 0;
}
