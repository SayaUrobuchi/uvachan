#include<iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int ary[1048576];

int main()
{
	int n, i, cx, cy, x, y, d;
	while (scanf("%d%d%d", &cx, &cy, &n) == 3)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d%d", &x, &y, &d);
			ary[i] = max(0.0, floor(sqrt((cx-x)*(cx-x) + (cy-y)*(cy-y)) - d));
		}
		sort(ary, ary+n);
		printf("%d\n", ary[2]);
	}
	return 0;
}
