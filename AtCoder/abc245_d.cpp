#include <iostream>
using namespace std;

const int N = 128;

int ary[N], bry[N], cry[N+N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=0; i<=n+m; i++)
	{
		scanf("%d", &cry[i]);
	}
	for (i=m, j=n+m; i>=0; i--, j--)
	{
		int t = cry[j];
		int a, b;
		for (b=m, a=j-b; b>i; b--, a++)
		{
			if (a >= 0)
			{
				t -= bry[b] * ary[a];
			}
		}
		t /= ary[n];
		bry[i] = t;
	}
	for (i=0; i<=m; i++)
	{
		printf("%d%c", bry[i], " \n"[i==m]);
	}
	return 0;
}
