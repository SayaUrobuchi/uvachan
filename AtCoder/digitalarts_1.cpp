#include <iostream>
#include <cstring>
using namespace std;

const int N = 64;
const int PLEN = 32;
const int SLEN = 1005;
const char *STAR = "********************************";

int len[N];
char pat[N][PLEN];
char s[SLEN], buf[SLEN];

int main()
{
	int n, i, j;
	fgets(s, sizeof(s), stdin);
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", pat[i]);
		len[i] = strlen(pat[i]);
	}
	int pos = 0;
	int step;
	bool first = true;
	while (sscanf(s+pos, "%s%n", buf, &step) == 1)
	{
		pos += step;
		int l = strlen(buf);
		bool pass = true;
		for (i=0; i<n&&pass; i++)
		{
			if (len[i] == l)
			{
				bool fit = true;
				for (j=0; j<l&&fit; j++)
				{
					if (pat[i][j] != '*' && buf[j] != pat[i][j])
					{
						fit = false;
					}
				}
				if (fit)
				{
					pass = false;
				}
			}
		}
		if (!first)
		{
			putchar(' ');
		}
		first = false;
		if (pass)
		{
			printf("%s", buf);
		}
		else
		{
			printf("%.*s", l, STAR);
		}
	}
	puts("");
	return 0;
}
