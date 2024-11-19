#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int best = 0;
	int ans;
	for (i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > best)
		{
			best = a;
			ans = a + b;
		}
	}
	printf("%d\n", ans);
	return 0;
}