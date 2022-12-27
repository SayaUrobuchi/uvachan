#include <iostream>
using namespace std;

int main()
{
	int n, m, i, j, a, b, c, t, ans;
	scanf("%d%d%d%d%d", &a, &b, &c, &n, &m);
	for (i=0, j=0, ans=2e9; i<=n||i<=m; i++, j+=2)
	{
		t = j * c;
		if (i < n)
		{
			t += (n-i) * a;
		}
		if (i < m)
		{
			t += (m-i) * b;
		}
		ans = min(ans, t);
	}
	printf("%d\n", ans);
	return 0;
}