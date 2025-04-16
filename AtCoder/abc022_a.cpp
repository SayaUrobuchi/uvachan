#include <iostream>
using namespace std;

bool in_range(int c, int a, int b)
{
	return c >= a && c <= b;
}

int main()
{
	int n, p, q, cur, i;
	scanf("%d%d%d", &n, &p, &q);
	scanf("%d", &cur);
	int ans = in_range(cur, p, q);
	for (i=1; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		cur += t;
		ans += in_range(cur, p, q);
	}
	printf("%d\n", ans);
	return 0;
}
