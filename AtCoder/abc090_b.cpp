#include <iostream>
using namespace std;

int main()
{
	int a, b, i, j, t, ans;
	scanf("%d%d", &a, &b);
	for (i=a, ans=0; i<=b; i++)
	{
		for (j=0, t=i; t; j=j*10+t%10, t/=10);
		ans += (i == j);
	}
	printf("%d\n", ans);
	return 0;
}