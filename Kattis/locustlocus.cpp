#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	while ((a %= b) && (b %= a));
	return a + b;
}

int main()
{
	int n, i, y, a, b, lcm, best;
	scanf("%d", &n);
	for (i=0, best=1000000; i<n; i++)
	{
		scanf("%d%d%d", &y, &a, &b);
		lcm = a * b / gcd(a, b);
		best = min(best, y+lcm);
	}
	printf("%d\n", best);
	return 0;
}
