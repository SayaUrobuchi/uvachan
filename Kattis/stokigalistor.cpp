#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000005;

int ary[N], bry[N];

int main()
{
	int n, i, ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		bry[i] = ary[i];
	}
	sort(bry, bry+n);
	for (i=0, ans=0; i<n; i++)
	{
		ans += (ary[i] != bry[i]);
	}
	printf("%d\n", ans);
	return 0;
}
