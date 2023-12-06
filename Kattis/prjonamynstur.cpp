#include <iostream>
using namespace std;

int tbl[128];
char s[1024];

int main()
{
	int n, m, i, j, ans;
	tbl['.'] = 20;
	tbl['O'] = 10;
	tbl['\\'] = 25;
	tbl['/'] = 25;
	tbl['A'] = 35;
	tbl['^'] = 5;
	tbl['v'] = 22;
	scanf("%d%d", &n, &m);
	for (i=0, ans=0; i<n; i++)
	{
		scanf("%s", s);
		for (j=0; j<m; j++)
		{
			ans += tbl[s[j]];
		}
	}
	printf("%d\n", ans);
	return 0;
}
