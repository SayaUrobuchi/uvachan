#include <iostream>
using namespace std;

int main()
{
	int n, m, i, a, b, l, r;
	scanf("%d%d", &n, &m);
	for (i=0, l=1, r=n; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		l = max(l, a);
		r = min(r, b);
	}
	printf("%d\n", max(l-1, r)-l+1);
	return 0;
}