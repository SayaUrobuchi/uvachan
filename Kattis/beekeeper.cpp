#include <iostream>
#include <cstring>

const char *key = "aeiouy";
bool tbl[128];
char s[1024], ans[1024];

int main()
{
	int n, i, j, t, best;
	for (i=0; key[i]; i++)
	{
		tbl[key[i]] = true;
	}
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=0, best=-1; i<n; i++)
		{
			scanf("%s", s);
			for (j=1, t=0; s[j]; j++)
			{
				if (tbl[s[j]] && s[j] == s[j-1])
				{
					++t;
				}
			}
			if (t > best)
			{
				best = t;
				strcpy(ans, s);
			}
		}
		puts(ans);
	}
	return 0;
}
