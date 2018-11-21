#include <stdio.h>
#include <string.h>

int ary[9][1024], an[9], qq[1048576];
char s[1048576];

int parse(char *s)
{
	if (strcmp(s, "HR") == 0)
	{
		return 4;
	}
	if (*s >= '0' && *s <= '9')
	{
		return *s-'0';
	}
	return -1;
}

int main()
{
	int i, j, a, b, out, ans, c, k;
	while (1)
	{
		for (i=0; i<9; i++)
		{
			if (scanf("%d", &an[i]) == EOF)
			{
				return 0;
			}
			for (j=0; j<an[i]; j++)
			{
				scanf("%s", s);
				ary[i][j] = parse(s);
			}
		}
		scanf("%d", &c);
		a = 0;
		b = 0;
		i = 0;
		j = 0;
		out = 0;
		ans = 0;
		while (c)
		{
			if (ary[a][b] < 0)
			{
				++out;
				--c;
				if (out >= 3)
				{
					i = j;
					out = 0;
				}
			}
			else
			{
				qq[j] = 0;
				j++;
				for (k=i; k<j; k++)
				{
					qq[k] += ary[a][b];
					if (qq[k] >= 4)
					{
						i++;
						ans++;
					}
				}
			}
			a++;
			if (a >= 9)
			{
				a = 0;
				b++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
