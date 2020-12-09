#include <iostream>

int ary[32][32];

int main()
{
	int n, i, j;
	bool same;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[0][i]);
		}
		for (i=1; i<n; i++)
		{
			for (j=0, same=true; j<n-i; j++)
			{
				ary[i][j] = ary[i-1][j+1] - ary[i-1][j];
				if (j)
				{
					if (ary[i][j] != ary[i][j-1])
					{
						same = false;
					}
				}
			}
			if (same)
			{
				ary[i][n-i] = ary[i][n-i-1];
				break;
			}
		}
		printf("%d ", i);
		for (i--; i>=0; i--)
		{
			ary[i][n-i] = ary[i][n-i-1] + ary[i+1][n-i-1];
		}
		printf("%d\n", ary[0][n]);
	}
	return 0;
}
