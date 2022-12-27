#include <iostream>
using namespace std;

int dsum(int t)
{
	int res;
	for (res=0; t; res+=t%10, t/=10);
	return res;
}

int main()
{
	int n, i, j, ans;
	scanf("%d", &n);
	for (i=1, ans=1e9; i<n; i++)
	{
		j = n-i;
		ans = min(ans, dsum(i)+dsum(j));
	}
	printf("%d\n", ans);
	return 0;
}