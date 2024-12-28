#include <iostream>
using namespace std;

int main()
{
	int n, w;
	scanf("%d%d", &n, &w);
	int total = n * 3 + w;
	int ans = total / 2;
	printf("%d\n", ans);
	return 0;
}
