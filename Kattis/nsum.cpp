#include <iostream>
using namespace std;

int main()
{
	int n, i, t, ans;
	scanf("%d", &n);
	for (i=0, ans=0; i<n; i++)
	{
		scanf("%d", &t);
		ans += t;
	}
	printf("%d\n", ans);
	return 0;
}