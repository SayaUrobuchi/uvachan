#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;

int ary[N];

int main()
{
	int n, i, ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	for (i=0, ans=0; i+i<n; i++)
	{
		ans += ary[i] >> 1;
	}
	for (; i<n; i++)
	{
		ans += ary[i];
	}
	printf("%d\n", ans);
	return 0;
}
