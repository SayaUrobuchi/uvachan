#include <iostream>
using namespace std;

const int N = 1005;
const int M = 32;

char tbl[N][M];
bool alive[N];
char s[8];

int main()
{
	int n, m, o, i, j, pos, cnt, ans;
	scanf("%d%d%d", &n, &m, &o);
	for (i=1; i<=n; i++)
	{
		scanf("%s", tbl[i]+1);
		alive[i] = true;
	}
	for (i=0; i<o; i++)
	{
		scanf("%d%s", &pos, s);
		for (j=1; j<=n; j++)
		{
			alive[j] &= (tbl[j][pos] == *s);
		}
	}
	for (i=1, cnt=0; i<=n; i++)
	{
		if (alive[i])
		{
			++cnt;
			ans = i;
		}
	}
	if (cnt == 1)
	{
		printf("unique\n%d\n", ans);
	}
	else
	{
		printf("ambiguous\n%d\n", cnt);
	}
	return 0;
}
