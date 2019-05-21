#include <stdio.h>

const char *str[] = {
	"Square",
	"Rectangle",
	"Rhombus",
	"Parallelogram",
	"Trapezium",
	"Ordinary Quadrilateral"
};

int ans;
int ary[4], dx[4], dy[4], len[4], ang[4];
int px[4], py[4];

void calc(int a, int b, int c, int d)
{
	int i, j, k, dir;
	ary[0] = a;
	ary[1] = b;
	ary[2] = c;
	ary[3] = d;
	for (k=0; k<4; k++)
	{
		i = ary[k];
		j = ary[(k+1)&3];
		dx[k] = px[i] - px[j];
		dy[k] = py[i] - py[j];
		len[k] = dx[k]*dx[k] + dy[k]*dy[k];
	}
	for (i=0; i<4; i++)
	{
		ang[i] = dx[i]*dx[(i+1)&3] + dy[(i+1)&3]*dy[i];
	}
	dir = dx[0]*dy[1] - dx[1]*dy[0];
	for (i=1; i<4; i++)
	{
		k = dx[i]*dy[(i+1)&3] - dx[(i+1)&3]*dy[i];
		if ((long long)k*dir < 0)
		{
			return;
		}
		dir = k;
	}
	if (!ang[0] && !ang[1] && !ang[2] && !ang[3])
	{
		if (len[0] == len[1] && len[0] == len[2] && len[0] == len[3])
		{
			ans = 0;
		}
		else
		{
			if (ans > 1)
			{
				ans = 1;
			}
		}
	}
	else
	{
		if (len[0] == len[1] && len[0] == len[2] && len[0] == len[3])
		{
			if (ans > 2)
			{
				ans = 2;
			}
		}
		else if (len[0] == len[2] && len[1] == len[3])
		{
			if (ans > 3)
			{
				ans = 3;
			}
			//printf("%d %d %d %d\n", a, b, c, d);
		}
		else if ((dx[0]*dy[2] - dx[2]*dy[0] == 0) || 
				 (dx[1]*dy[3] - dx[3]*dy[1] == 0))
		{
			if (ans > 4)
			{
				ans = 4;
			}
		}
	}
}

int main()
{
	int count, i, cas;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		for (i=0; i<4; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
		}
		ans = 5;
		calc(0, 1, 2, 3);
		calc(0, 1, 3, 2);
		calc(0, 2, 1, 3);
		calc(0, 2, 3, 1);
		printf("Case %d: %s\n", ++cas, str[ans]);
	}
	return 0;
}
