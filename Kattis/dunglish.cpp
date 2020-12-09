#include <iostream>
#include <unordered_map>
using namespace std;

using ii = __int128_t;

ii dpc[32], dpi[32];
char str[32][1024], *p;
char s[1024], t[1024], u[1024], v[1024];

char *tos(ii t)
{
	char *p = v+512;
	*p-- = 0;
	for (; t>9; t/=10, --p)
	{
		*p = t%10 + '0';
	}
	*p = t%10 + '0';
	return p;
}

int main()
{
	int n, m, i, a, b;
	unordered_map<string, int> cor, inc;
	unordered_map<string, string> dic;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", str[i]);
		}
		cor.clear();
		inc.clear();
		dic.clear();
		scanf("%d", &m);
		for (i=0; i<m; i++)
		{
			scanf("%s%s%s", s, t, u);
			if (*u == 'i')
			{
				++inc[s];
			}
			else
			{
				++cor[s];
			}
			dic[s] = t;
		}
		dpc[0] = 1;
		dpi[0] = 0;
		for (i=1; i<=n; i++)
		{
			p = str[i-1];
			a = cor[p];
			b = inc[p];
			dpc[i] = dpc[i-1] * a;
			dpi[i] = dpi[i-1] * (a+b) + dpc[i-1] * b;
			//printf("%d: %s", i, tos(dpc[i]));
			//printf(" %s\n", tos(dpi[i]));
		}
		if (dpc[n] + dpi[n] != 1)
		{
			printf("%s correct\n", tos(dpc[n]));
			printf("%s incorrect\n", tos(dpi[n]));
		}
		else
		{
			printf("%s", dic[*str].c_str());
			for (i=1; i<n; i++)
			{
				printf(" %s", dic[str[i]].c_str());
			}
			printf("\n%s\n", dpc[n]?"correct":"incorrect");
		}
	}
	return 0;
}
