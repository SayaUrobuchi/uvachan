#include <stdio.h>

int ary[32][32], used[32][32], edg[32];

int main()
{
	int count, cnt, i, j, k, n, m;
	cnt = 0;
	scanf("%d", &count);
	while (count--)
	{
		++cnt;
		scanf("%d%d", &n, &m);
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		for (j=0; j<m; j++)
		{
			for (i=0, k=0; i<n&&k<3; i++)
			{
				if (ary[i][j])
				{
					edg[k++] = i;
				}
			}
			if (k != 2)
			{
				break;
			}
			i = edg[0];
			k = edg[1];
			if (used[i][k] == cnt)
			{
				break;
			}
			used[i][k] = used[k][i] = cnt;
		}
		puts(j<m ? "No" : "Yes");
	}
	return 0;
}
