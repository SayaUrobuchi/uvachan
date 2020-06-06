#include <stdio.h>

int ary[1024][4];

int main()
{
	int a, b, c, d, i;
	while (scanf("%d%d%d%d%d%d%d", &ary[0][2], &ary[0][1], &ary[0][0], &a, &b, &c, &d) == 7)
	{
		for (i=1; i<=d; i++)
		{
			ary[i][0] = ary[i-1][2] * a;
			ary[i][1] = ary[i-1][0] / b;
			ary[i][2] = ary[i-1][1] / c;
		}
		printf("%d\n", ary[d][2]);
	}
}
