#include <iostream>
using namespace std;

int main()
{
	int n, x, y, z;
	scanf("%d%d%d%d", &n, &x, &y, &z);
	bool ans = (z >= min(x, y) && z <= max(x, y));
	puts(ans ? "Yes" : "No");
	return 0;
}
