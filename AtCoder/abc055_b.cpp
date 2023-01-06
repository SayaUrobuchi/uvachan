#include <iostream>
using namespace std;

const int M = 1000000007;

int main()
{
	int n, i, ans;
	scanf("%d", &n);
	for (i=2, ans=1; i<=n; i++)
	{
		ans = ((long long)ans * i) % M;
	}
	printf("%d\n", ans);
	return 0;
}
