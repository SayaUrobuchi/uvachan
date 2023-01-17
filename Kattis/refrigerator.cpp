#include <iostream>
using namespace std;

int main()
{
	int n, i, j, t, best, aa, ab, ca, cb, va, vb, lim;
	scanf("%d%d%d%d%d", &ca, &va, &cb, &vb, &n);
	aa = 0;
	ab = (n+vb-1) / vb;
	best = ab * cb;
	for (i=1, lim=(n+(va-1))/va; i<=lim; i++)
	{
		j = (max(0, n-va*i)+vb-1) / vb;
		t = i * ca + j * cb;
		if (t < best)
		{
			best = t;
			aa = i;
			ab = j;
		}
	}
	printf("%d %d %d\n", aa, ab, best);
	return 0;
}
