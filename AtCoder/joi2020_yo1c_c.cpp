#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int last = -1e9;
	int len = 0;
	int ans = 1;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t < last)
		{
			len = 0;
		}
		++len;
		ans = max(ans, len);
		last = t;
	}
	printf("%d\n", ans);
	return 0;
}
