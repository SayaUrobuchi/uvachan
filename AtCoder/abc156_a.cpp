#include <iostream>
using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = m + 100 * max(0, 10-n);
	printf("%d\n", ans);
	return 0;
}
