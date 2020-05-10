#include <stdio.h>

int rotn[8] = {0, 2, 1, 2, 2, 4, 4, 4};
int tbl[8][4][8] = {
	{
	},
	{
		{1},
		{4, 0, 0, 0}
	},
	{
		{2, 0}
	},
	{
		{3, 0, 1},
		{2, -1}
	},
	{
		{3, -1, 0},
		{2, 1}
	},
	{
		{3, 0, 0},
		{2, 1},
		{3, -1, 1},
		{2, -1}
	},
	{
		{3, 0, 0},
		{2, 0},
		{3, 1, 0},
		{2, -2}
	},
	{
		{3, 0, 0},
		{2, 2},
		{3, 0, -1},
		{2, 0}
	}
};

int ary[128];

int main()
{
	int n, m, i, j, k, flag, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0, ans=0; i<rotn[m]; i++)
		{
			for (j=0; j+tbl[m][i][0]<=n; j++)
			{
				flag = 1;
				for (k=j+1; k<j+tbl[m][i][0]; k++)
				{
					if (ary[k]-ary[k-1] != tbl[m][i][k-j])
					{
						flag = 0;
						break;
					}
				}
				ans += flag;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
