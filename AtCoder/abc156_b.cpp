#include <iostream>
using namespace std;

int main()
{
	int n, m, ans;
	scanf("%d%d", &n, &m);
	for (ans=1; n>=m; n/=m, ans++);
	printf("%d\n", ans);
	return 0;
}