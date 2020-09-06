#include <stdio.h>

const int REC = 0;
const int CIR = 1;

int typ[256], ary[256][4];
char buf[256];

int main()
{
	int n, m, i, j, t, x, y;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", buf);
			if (*buf == 'r')
			{
				typ[i] = REC;
				t = 4;
			}
			else
			{
				typ[i] = CIR;
				t = 3;
			}
			for (j=0; j<t; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		scanf("%d", &m);
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &x, &y);
			for (j=0, t=0; j<n; j++)
			{
				if (typ[j] == REC)
				{
					if (x >= ary[j][0] && x <= ary[j][2] && y >= ary[j][1] && y <= ary[j][3])
					{
						++t;
					}
				}
				else
				{
					if ((x-ary[j][0])*(x-ary[j][0]) + (y-ary[j][1])*(y-ary[j][1]) <= ary[j][2]*ary[j][2])
					{
						++t;
					}
				}
			}
			printf("%d\n", t);
		}
	}
	return 0;
}
