#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int r, a, b;
	scanf("%d%d%d", &r, &a, &b);
	double d = sqrt(1LL*a*a + 1LL*b*b);
	int ans = d / r;
	if (fmod(d, r) > 0)
	{
		ans += 1 + !ans;
	}
	printf("%d\n", ans);
	return 0;
}
