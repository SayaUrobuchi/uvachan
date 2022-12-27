#include <iostream>
using namespace std;

int main()
{
	int a, b, c, p, q, r;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		p = min(a, min(b, c));
		r = max(a, max(b, c));
		q = a+b+c - p - r;
		if (q-p == r-q)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}

