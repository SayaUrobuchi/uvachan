#include <iostream>
using namespace std;

int n;
int ary[262144];

int fix(int t, int s)
{
	return 1+((-s)%n+n+(t-1))%n;
}

int main()
{
	int m, i, a, b, cmd, shift;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0, shift=0; i<m; i++)
		{
			scanf("%d%d%d", &cmd, &a, &b);
			if (cmd == 1)
			{
				swap(ary[fix(a, shift)], ary[fix(b, shift)]);
			}
			else if (cmd == 2)
			{
				++shift;
			}
			else
			{
				printf("%d\n", ary[fix(a, shift)]);
			}
		}
	}
	return 0;
}
