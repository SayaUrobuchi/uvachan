#include <iostream>
using namespace std;

int main()
{
	int n, i, a, b, l, r, t, u, v;
	scanf("%d%d%d", &n, &a, &b);
	scanf("%d", &l);
	r = l;
	for (i=2; i<n; i++)
	{
		scanf("%d", &t);
		l = min(l, t);
		r = max(r, t);
	}
	if (l != a && r != b)
	{
		puts("-1");
	}
	else
	{
		if (l != a)
		{
			u = v = a;
		}
		else if (r != b)
		{
			u = v = b;
		}
		else
		{
			u = l;
			v = r;
		}
		for (i=u; i<=v; i++)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
