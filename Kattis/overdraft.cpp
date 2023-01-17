#include <iostream>
using namespace std;

int main()
{
	int n, i, t, sum, ans;
	scanf("%d", &n);
	for (i=0, sum=0, ans=0; i<n; i++)
	{
		scanf("%d", &t);
		sum += t;
		ans = min(sum, ans);
	}
	printf("%d\n", abs(ans));
	return 0;
}
