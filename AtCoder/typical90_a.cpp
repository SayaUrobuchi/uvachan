#include <iostream>
using namespace std;

int n;
int ary[1048576];

bool judge(int lim, int cnt)
{
	int i, last;
	for (i=0, last=0; i<n&&cnt>0; i++)
	{
		if (ary[i] - last >= lim)
		{
			--cnt;
			last = ary[i];
		}
	}
	return cnt <= 0;
}

int main()
{
	int m, o, i, p, q, mid, ans;
	while (scanf("%d%d", &n, &o) == 2)
	{
		scanf("%d", &m);
		++m;
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		ary[n++] = o;
		for (p=0, q=o; p<=q; )
		{
			mid = ((p+q) >> 1);
			if (judge(mid, m))
			{
				p = mid+1;
				ans = mid;
			}
			else
			{
				q = mid-1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
