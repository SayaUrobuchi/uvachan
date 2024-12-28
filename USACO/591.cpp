#include <iostream>
using namespace std;

const int N = 4;

int a[N], b[N], c[N];

int main()
{
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
	int i;
	for (i=0; i<4; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
	}
	for (i=3; i>0; i--)
	{
		c[i] = b[i] - a[i];
		b[i-1] += c[i];
	}
	for (i=1; i<=3; i++)
	{
		printf("%d\n", c[i]);
	}
	return 0;
}
