#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

int ary[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	int ans = 0;
	for (i=0; i<n; i=j)
	{
		for (j=i+1; j<n&&ary[i]==ary[j]; j++);
		int cnt = j - i;
		if (cnt < ary[i])
		{
			ans += cnt;
		}
		else
		{
			ans += cnt - ary[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
