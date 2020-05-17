#include <stdio.h>

int val[128][16384], neg[128][16384], pn[128];
char s[1048576], buf[1048576];

int main()
{
	int count, n, m, i, j, k, t, res;
	char *p;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		fgets(s, sizeof(s), stdin);
		for (i=0; i<m; i++)
		{
			fgets(s, sizeof(s), stdin);
			for (p=s, j=0; *p; j++)
			{
				if (sscanf(p, " %[^0-9]%d%n", buf, &val[i][j], &t) != 2)
				{
					break;
				}
				val[i][j]--;
				neg[i][j] = (*buf == '~' ? 1 : 0);
				//printf("=== %sX%d ===\n", neg[i][j]?"~":"", val[i][j]);
				p += t;
				t = 0;
				sscanf(p, "%*s%n", &t);
				//printf("tt %d\n", t);
				p += t;
			}
			pn[i] = j;
		}
		for (i=0; i<(1<<n); i++)
		{
			for (j=0; j<m; j++)
			{
				for (k=0, res=0; k<pn[j]&&!res; k++)
				{
					if (neg[j][k])
					{
						res |= !(i & (1<<val[j][k]));
					}
					else
					{
						res |= (i & (1<<val[j][k]));
					}
				}
				if (!res)
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
			puts("satisfiable");
		}
		else
		{
			puts("unsatisfiable");
		}
	}
	return 0;
}
