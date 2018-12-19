#include <stdio.h>
#include <string.h>

const int N = 1024;
const int NAM_LEN = 16;
const int EXT_LEN = 8;

int first;
int dc, pc;
char dnam[N][NAM_LEN], dext[N][EXT_LEN];
char pnam[N][NAM_LEN], pext[N][EXT_LEN];
char nam_pat[NAM_LEN], ext_pat[EXT_LEN];
int dnl[N], del[N];
char s[NAM_LEN+EXT_LEN];

void init()
{
	dc = 0;
	pc = 0;
}

int match(char *pat, char *str, int len, int star)
{
	int i;
	int slen = strlen(str);
	if (!star && slen != len)
	{
		return 0;
	}
	if (slen < len)
	{
		return 0;
	}
	for (i=0; i<len; i++)
	{
		if (pat[i] != '?' && pat[i] != str[i])
		{
			return 0;
		}
	}
	return 1;
}

void solve()
{
	int min_nam, min_ext, max_nam, max_ext, nam_star, ext_star, i, j, k, ac;
	if (!first)
	{
		puts("");
	}
	first = 0;
	min_nam = 16;
	min_ext = 16;
	max_nam = 0;
	max_ext = 0;
	for (i=0; i<dc; i++)
	{
		if (dnl[i] < min_nam)
		{
			min_nam = dnl[i];
		}
		if (dnl[i] > max_nam)
		{
			max_nam = dnl[i];
		}
		if (del[i] < min_ext)
		{
			min_ext = del[i];
		}
		if (del[i] > max_ext)
		{
			max_ext = del[i];
		}
	}
	strcpy(nam_pat, dnam[0]);
	strcpy(ext_pat, dext[0]);
	for (i=1; i<dc; i++)
	{
		for (j=0; j<min_nam; j++)
		{
			if (dnam[i][j] != nam_pat[j])
			{
				nam_pat[j] = '?';
			}
		}
		for (j=0; j<min_ext; j++)
		{
			if (dext[i][j] != ext_pat[j])
			{
				ext_pat[j] = '?';
			}
		}
	}
	nam_star = 1;
	ext_star = 1;
	if (max_nam == min_nam && strchr(nam_pat, '?') == NULL)
	{
		nam_star = 0;
	}
	if (max_ext == min_ext && strchr(ext_pat, '?') == NULL)
	{
		ext_star = 0;
	}
	//printf("%d %d %d %d %s\n", nam_star, ext_star, min_ext, max_ext, ext_pat);
	ac = 0;
	for (i=0; i<=min_nam&&!ac; i++)
	{
		if (!nam_star)
		{
			i = min_nam;
		}
		for (j=0; j<=min_ext&&!ac; j++)
		{
			if (!ext_star)
			{
				j = min_ext;
			}
			for (k=0; k<pc; k++)
			{
				if (match(nam_pat, pnam[k], i, nam_star) && match(ext_pat, pext[k], j, ext_star))
				{
					break;
				}
			}
			if (k >= pc)
			{
				printf("DEL %.*s%.*s.%.*s%.*s\n", i, nam_pat, nam_star, "*", j, ext_pat, ext_star, "*");
				ac = 1;
			}
		}
	}
	if (!ac)
	{
		puts("IMPOSSIBLE");
	}
}

int main()
{
	int count, i;
	const char *p;
	scanf("%d", &count);
	fgets(s, 1024, stdin);
	fgets(s, 1024, stdin);
	init();
	first = 1;
	while (fgets(s, 1024, stdin))
	{
		for (i=strlen(s)-1; i>=0&&s[i]<' '; i--)
		{
			s[i] = '\0';
		}
		if (*s == '\0')
		{
			solve();
			init();
			--count;
			continue;
		}
		if (*s == '-')
		{
			strcpy(dnam[dc], strtok(s+1, "."));
			p = strtok(NULL, ".");
			if (p == NULL)
			{
				p = "";
			}
			strcpy(dext[dc], p);
			dnl[dc] = strlen(dnam[dc]);
			del[dc] = strlen(dext[dc]);
			dc++;
		}
		else
		{
			strcpy(pnam[pc], strtok(s+1, "."));
			p = strtok(NULL, ".");
			if (p == NULL)
			{
				p = "";
			}
			strcpy(pext[pc], p);
			pc++;
		}
	}
	if (count)
	{
		solve();
	}
	return 0;
}
