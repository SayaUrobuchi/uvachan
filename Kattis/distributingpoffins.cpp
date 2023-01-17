#include <iostream>
using namespace std;

int main()
{
	int n, m;
	bool ans;
	scanf("%d%d", &m, &n);
	ans = n % m;
	printf("%d\n", ans);
	return 0;
}
