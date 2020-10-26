#include <iostream>

int used[64][64];
int px[64], py[64];

int main()
{
	int count, n, m, i, j, k, t, d, x, y, ucnt;
	bool found;
	ucnt = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		++ucnt;
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			used[px[i]][py[i]] = ucnt;
		}
		for (i=0, found=false; i<=n&&!found; i++)
		{
			for (j=0; j<=n&&!found; j++)
			{
				if (used[i][j] != ucnt)
				{
					for (k=0, d=0; k<m; k++)
					{
						t = (i-px[k])*(i-px[k]) + (j-py[k])*(j-py[k]);
						if (t > d)
						{
							d = t;
							if (d > i*i || d > (n-i)*(n-i) || d > j*j || d > (n-j)*(n-j))
							{
								break;
							}
						}
					}
					if (k >= m)
					{
						found = true;
						x = i;
						y = j;
					}
				}
			}
		}
		if (found)
		{
			printf("%d %d\n", x, y);
		}
		else
		{
			puts("poodle");
		}
	}
	return 0;
}
