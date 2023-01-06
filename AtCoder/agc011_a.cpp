#include <iostream>
#include <algorithm>
using namespace std;

int ary[100005];

int main()
{
	int n, i, cap, lim, last, cnt, ans;
	scanf("%d%d%d", &n, &cap, &lim);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	for (i=1, ans=1, last=ary[0], cnt=1; i<n; i++)
	{
		if (ary[i] > last + lim || cnt == cap)
		{
			++ans;
			last = ary[i];
			cnt = 1;
		}
		else
		{
			++cnt;
		}
	}
	printf("%d\n", ans);
	return 0;
}