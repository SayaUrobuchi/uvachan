#include <iostream>
using namespace std;

char buf[16];

int main()
{
	int n, i, a, b, best;
	string best_nam;
	scanf("%d", &n);
	best = -1;
	for (i=0; i<n; i++)
	{
		scanf("%s%d%d", buf, &a, &b);
		int t = (a + 1) * b;
		if (t > best)
		{
			best = t;
			best_nam = buf;
		}
	}
	printf("%s %d\n", best_nam.c_str(), best);
	return 0;
}
