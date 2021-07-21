#include <iostream>
using namespace std;
using mat = char (*)[16];

const char *space = "                                                                                 ";
char buf[16][16], buf2[16][16];

int main()
{
	int n, m, i, j, k, x, y, d;
	mat a, b;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", buf[i]);
		}
		scanf("%d", &d);
		d = (d/45) % 8;
		a = buf2;
		b = buf;
		for (k=2; k<=d; k+=2)
		{
			swap(n, m);
			swap(a, b);
			for (i=0; i<n; i++)
			{
				for (j=0; j<m; j++)
				{
					b[i][j] = a[m-j-1][i];
				}
			}
		}
		if (d & 1)
		{
			for (i=0, j=n-1; j>=0; j--, i++)
			{
				printf("%.*s", j, space);
				for (x=min(i, n-1), y=max(0, i-n+1), k=0; x>=0&&y<m; x--, y++, k++)
				{
					if (k)
					{
						putchar(' ');
					}
					printf("%c", b[x][y]);
				}
				puts("");
			}
			for (j=1; j<m; i++, j++)
			{
				printf("%.*s", j, space);
				for (x=min(i, n-1), y=max(0, i-n+1), k=0; x>=0&&y<m; x--, y++, k++)
				{
					if (k)
					{
						putchar(' ');
					}
					printf("%c", b[x][y]);
				}
				puts("");
			}
		}
		else
		{
			for (i=0; i<n; i++)
			{
				puts(b[i]);
			}
		}
	}
	return 0;
}
