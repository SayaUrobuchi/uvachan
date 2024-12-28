#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int x = n * 800;
	int y = (n / 15) * 200;
	int ans = x - y;
	printf("%d\n", ans);
	return 0;
}
