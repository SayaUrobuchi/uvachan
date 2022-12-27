#include <iostream>
using namespace std;

int main()
{
	int n, a, b, i, j, t, ans;
	scanf("%d%d%d", &n, &a, &b);
	for (i=1, ans=0; i<=n; i++)
	{
		for (j=i, t=0; j; t+=j%10, j/=10);
		if (t >= a && t <= b)
		{
			ans += i;
		}
	}
	printf("%d\n", ans);
	return 0;
}