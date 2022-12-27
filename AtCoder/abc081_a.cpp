#include <iostream>
using namespace std;

int main()
{
	int n, ans;
	scanf("%d", &n);
	for (ans=0; n; ans+=n%10, n/=10);
	printf("%d\n", ans);
	return 0;
}