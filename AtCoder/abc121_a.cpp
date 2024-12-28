#include <iostream>
using namespace std;

int main()
{
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	int ans = n*m - a*m - b*n + a*b;
	printf("%d\n", ans);
	return 0;
}
