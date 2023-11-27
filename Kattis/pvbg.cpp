#include <iostream>
using namespace std;

int main()
{
	int n, i, ans;
	scanf("%d", &n);
	ans = 2e9;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		ans = min(ans, t);
	}
	printf("%d\n", ans+1);
	return 0;
}
