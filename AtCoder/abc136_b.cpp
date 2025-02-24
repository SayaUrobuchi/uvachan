#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int ans = 0;
	for (i=1; i<=n; i++)
	{
		int dig = 1;
		for (j=i; j>9; ++dig, j/=10);
		ans += (dig & 1);
	}
	printf("%d\n", ans);
	return 0;
}
