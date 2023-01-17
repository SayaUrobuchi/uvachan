#include <iostream>
using namespace std;

int main()
{
	int n, m, o, i, t, last, top, down;
	scanf("%d%d%d", &o, &m, &n);
	top = 0;
	down = m;
	for (i=0, last=0; i<n; i++, last=t)
	{
		scanf("%d", &t);
		down += min(top, t-last);
		top -= min(top, t-last);
		swap(down, top);
	}
	printf("%d\n", max(0, last+top-o));
	return 0;
}
