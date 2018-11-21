#include <stdio.h>
#include <string.h>

int tbl[35][35], tp[35];
int lnum[35];
char str[35][35][100], res[35][100];

int to_up(int c)
{
	if(c >= 'a' && c <= 'z')
	{
		c = c - 'a' + 'A';
	}
	return c;
}

int to_low(int c)
{
	if(c >= 'A' && c <= 'Z')
	{
		c = c - 'A' + 'a';
	}
	return c;
}

char *adjust(char *s)
{
	int i;
	s[0] = to_up(s[0]);
	for(i=1; s[i]; i++)
	{
		s[i] = to_low(s[i]);
	}
	return s;
}

int main()
{
	int cas, count, n, i, j, k, l, c, tar;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		memset(tbl, 0, sizeof(tbl));
		memset(tp, 0, sizeof(tp));
		for(i=0; i<n; i++)
		{
			scanf("%d", &lnum[i]);
			for(j=0; j<lnum[i]; j++)
			{
				scanf("%s", str[i][j]);
				c = to_up(*str[i][j]) - 'A';
				tbl[c][tp[c]++] = i;
			}
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(tp[j] == 1)
				{
					break;
				}
			}
			tar = tbl[j][0];
			for(k=0; k<lnum[tar]; k++)
			{
				c = to_up(*str[tar][k]) - 'A';
				if(c == j)
				{
					strcpy(res[j], adjust(str[tar][k]));
				}
				for(l=0; l<tp[c]; l++)
				{
					if(tbl[c][l] == tar)
					{
						tbl[c][l] = tbl[c][--tp[c]];
						break;
					}
				}
			}
		}
		printf("Case #%d:\n", ++cas);
		for(i=0; i<n; i++)
		{
			printf("%s\n", res[i]);
		}
	}
	return 0;
}
