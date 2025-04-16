#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int ans = 0;
	for (i=1; i<=n; i+=2)
	{
		int t = 2;
		for (j=2; j*j<=i; j++)
		{
			if (i % j == 0)
			{
				++t;
				if (j * j != i)
				{
					++t;
				}
			}
		}
		ans += (t == 8);
	}
	printf("%d\n", ans);
	return 0;
}
