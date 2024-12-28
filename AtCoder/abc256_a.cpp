#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans = (1 << n);
	printf("%d\n", ans);
	return 0;
}
