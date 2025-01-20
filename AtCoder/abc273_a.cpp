#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int ans = 1;
	for (i=2; i<=n; i++)
	{
		ans *= i;
	}
	printf("%d\n", ans);
	return 0;
}
