#include <iostream>
using namespace std;

int main()
{
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	bool ans = (x + y <= z);
	printf("%d\n", ans);
	return 0;
}
