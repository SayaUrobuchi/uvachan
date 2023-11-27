#include <iostream>
using namespace std;

int main()
{
	int n, i, a, b, ans;
	scanf("%d%d%d", &n, &b, &a);
	for (i=0, ans=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t > a + b)
		{
			a = b;
			b = t;
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
