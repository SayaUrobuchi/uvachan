#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (i=1; i<=n&&i<m; i++)
	{
		int b = max(0, min(n, m-i));
		ans += b;
	}
	printf("%d\n", ans);
	return 0;
}
