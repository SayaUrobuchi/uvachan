#include <iostream>
using namespace std;

int ary[1048576];

int main()
{
	int n, m, i, t, sum;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &t);
			sum += abs(t-ary[i]);
		}
		if (sum <= m && !((m-sum)&1))
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}
