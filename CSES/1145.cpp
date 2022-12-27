#include <iostream>
#include <algorithm>
using namespace std;

int ary[200005];

int main()
{
	int n, i, j, k, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, t=1; i<n; i++)
		{
			scanf("%d", &k);
			j = lower_bound(ary, ary+t, k) - ary;
			ary[j] = k;
			t = max(t, j+1);
		}
		printf("%d\n", t-1);
	}
	return 0;
}

