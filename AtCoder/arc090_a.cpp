#include <iostream>
using namespace std;

int ary[2][105];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[0][i]);
		ary[0][i] += ary[0][i-1];
	}
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[1][i]);
		ary[1][i] += max(ary[0][i], ary[1][i-1]);
	}
	printf("%d\n", ary[1][n]);
	return 0;
}
