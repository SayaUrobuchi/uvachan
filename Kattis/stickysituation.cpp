#include<iostream>
#include <algorithm>
using namespace std;

long long ary[1048576];

int main()
{
	int n, i;
	bool f;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%lld", &ary[i]);
		}
		if (n > 128)
		{
			puts("possible");
			continue;
		}
		sort(ary, ary+n);
		for (i=2, f=false; i<n; i++)
		{
			if (ary[i] - ary[i-1] < ary[i-2])
			{
				f = true;
				break;
			}
		}
		puts(f?"possible":"impossible");
	}
	return 0;
}
