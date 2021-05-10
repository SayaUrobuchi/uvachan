#include <iostream>
#include <algorithm>
using namespace std;

int tbl[128];
char s[128];

int main()
{
	int n, m, i, j, o;
	while (scanf("%d%d", &n, &m) == 2)
	{
		scanf("%s", s);
		for (i=0; s[i]; i++)
		{
			tbl[s[i]] = 0;
		}
		scanf("%s", s+n);
		for (i=n; s[i]; i++)
		{
			tbl[s[i]] = 1;
		}
		reverse(s, s+n);
		scanf("%d", &o);
		for (i=0; i<o; i++)
		{
			for (j=0; j+1<n+m; j++)
			{
				if (tbl[s[j]] == 0 && tbl[s[j+1]] == 1)
				{
					swap(s[j], s[j+1]);
					++j;
				}
			}
		}
		puts(s);
	}
	return 0;
}
