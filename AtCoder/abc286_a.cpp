#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, a, b, c, d, i;
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	for (i=1; i<=n; i++)
	{
		int t;
		scanf("%d", &t);
		if (i >= a && i <= b)
		{
			ary[c+(i-a)] = t;
		}
		else if (i >= c && i <= d)
		{
			ary[a+(i-c)] = t;
		}
		else
		{
			ary[i] = t;
		}
	}
	for (i=1; i<=n; i++)
	{
		printf("%d%c", ary[i], " \n"[i==n]);
	}
	return 0;
}
