#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

bitset<1000005> dp;
char buf[2];

int main()
{
	int n, i, j, k, t;
	vector<int> v;
	while (scanf("%d", &n) == 1)
	{
		dp |= 1;
		for (i=0, t=0; i<n; i++)
		{
			scanf("%d", &k);
			dp |= (dp<<k);
			t += k;
		}
		printf("%d\n", dp.count()-1);
		buf[0] = 0;
		for (i=1; i<=t; i++)
		{
			if (dp.test(i))
			{
				printf("%s%d", buf, i);
				buf[0] = ' ';
			}
		}
		puts("");
	}
	return 0;
}

