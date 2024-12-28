#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans = (1000 - n % 1000) % 1000;
	printf("%d\n", ans);
	return 0;
}
