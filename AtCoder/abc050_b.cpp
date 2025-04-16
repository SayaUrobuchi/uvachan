#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, m, i;
	scanf("%d", &n);
	int sum = 0;
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		sum += ary[i];
	}
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int ans = sum + b - ary[a];
		printf("%d\n", ans);
	}
	return 0;
}
