#include <iostream>
using namespace std;

int main()
{
	int n, a, b, i;
	scanf("%d%d%d", &n, &a, &b);
	int ans;
	for (i=1; i<=n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == a+b)
		{
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}
