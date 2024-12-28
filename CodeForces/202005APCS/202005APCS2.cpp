#include <stdio.h>
#include <string.h>

int tbl[128];
char s[1048576];

int main()
{
	int n, m, i, j, c, t, x, st, best, cur, tt, bx, blen, bpos;
	while (scanf("%d%d", &n, &m) == 2)
	{
		scanf("%s", s);
		for (i=0, best=-1; i<n; i++)
		{
			memset(tbl, 0, sizeof(tbl));
			for (j=0, c=0, st=0, t=0, x=0, bx=0; j<m&&i+j<n; j++)
			{
				cur = i+j;
				if (tbl[s[cur]] == 0)
				{
					tbl[s[cur]]++;
					c++;
				}
				tt = 0;
				if (s[cur] >= '0' && s[cur] <= '9')
				{
					tt = 1;
				}
				else if (s[cur] >= 'a' && s[cur] <= 'z')
				{
					tt = 2;
				}
				else if (s[cur] >= 'A' && s[cur] <= 'Z')
				{
					tt = 3;
				}
				if (!(st & (1<<tt)))
				{
					st |= (1<<tt);
					t++;
				}
				if (j && s[cur] == s[cur-1])
				{
					x++;
				}
				//printf(".. %.*s: %d %d\n", j+1, s+i, c*t*(bx+1), best*(x+1));
				if (c*t*(bx+1) > best*(x+1) || (c*t*(bx+1) == best*(x+1) && j > blen))
				{
					bx = x;
					best = c*t;
					bpos = i;
					blen = j;
				}
			}
		}
		printf("%.*s\n", blen+1, s+bpos);
	}
	return 0;
}
