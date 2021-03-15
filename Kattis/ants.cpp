#include <iostream>
using namespace std;

int main()
{
	int count, n, m, i, a, b, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &m, &n);
		for (i=0, a=0, b=0; i<n; i++)
		{
			scanf("%d", &t);
			a = max(a, max(t, m-t));
			b = max(b, min(t, m-t));
		}
		printf("%d %d\n", b, a);
	}
	return 0;
}
