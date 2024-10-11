#include <iostream>
#include <bitset>
using namespace std;
using bs_t = bitset<10>;

const int N = 16;

int p[N];
bs_t ary[N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		for (j=0; j<t; j++)
		{
			int u;
			scanf("%d", &u);
			ary[i] |= (1 << (u-1));
		}
	}
	for (i=0; i<m; i++)
	{
		scanf("%d", &p[i]);
	}
	int ans = 0;
	for (i=0; i<(1<<n); i++)
	{
		bs_t b = i;
		bool ok = true;
		for (j=0; j<m&&ok; j++)
		{
			bs_t bb = b & ary[j];
			if ((bb.count() & 1) != p[j])
			{
				ok = false;
			}
		}
		ans += ok;
	}
	printf("%d\n", ans);
	return 0;
}
