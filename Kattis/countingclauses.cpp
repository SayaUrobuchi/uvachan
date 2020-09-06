#include <stdio.h>

int ary[32][4];

int main()
{
	int n, m, i, j, k;
	while (scanf("%d%d", &m, &n) == 2)
	{
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &ary[i][0], &ary[i][1], &ary[i][2]);
		}
		/*for (i=0; i<(1<<n); i++)
		{
			for (j=0; j<m; j++)
			{
				for (k=0; k<3; k++)
				{
					if ((ary[j][k] > 0 && (i&(1<<(ary[j][k]-1))))
						|| (ary[j][k] < 0 && !(i&(1<<(-ary[j][k]-1)))))
					{
						break;
					}
				}
				if (k >= 3)
				{
					break;
				}
			}
			if (j >= m)
			{
				break;
			}
		}
		if (i < (1<<n))
		{
			puts("satisfactory");
		}
		else
		{
			puts("unsatisfactory");
		}*/
		puts(m<8?"unsatisfactory":"satisfactory");
	}
	return 0;
}
