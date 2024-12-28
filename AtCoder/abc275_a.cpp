#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int ans;
	int height = 0;
	for (i=1; i<=n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t > height)
		{
			height = t;
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}
