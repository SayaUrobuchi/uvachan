#include <iostream>
using namespace std;

const int N = 1005;

int cnt[N];

int main()
{
	int n, m, i, a, b;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		cnt[a]++;
		cnt[b]++;
	}
	for (i=1; i<=n; i++)
	{
		if (i > 1)
		{
			putchar(' ');
		}
		printf("%d", cnt[i]-i);
	}
	puts("");
	return 0;
}
