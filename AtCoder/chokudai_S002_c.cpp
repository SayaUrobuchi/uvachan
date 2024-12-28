#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int ans = 0;
	for (i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		ans = max(ans, a + b);
	}
	printf("%d\n", ans);
	return 0;
}
