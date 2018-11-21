#include <stdio.h>

const char *pat = "ACGT";
char s[64][1024];

int main()
{
	int count, n, m, i, j, k, c, mc, mx, res;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i=0; i<n; i++)
		{
			scanf("%s", s[i]);
		}
		res = 0;
		for (i=0; i<m; i++)
		{
			mx = m;
			mc = 0;
			for (j=0; pat[j]; j++)
			{
				c = 0;
				for (k=0; k<n; k++)
				{
					if (pat[j] != s[k][i])
					{
						c++;
					}
				}
				if (c < mx)
				{
					mx = c;
					mc = j;
				}
			}
			putchar(pat[mc]);
			res += mx;
		}
		printf("\n%d\n", res);
	}
	return 0;
}
