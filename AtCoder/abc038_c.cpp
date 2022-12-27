#include <iostream>
using namespace std;

int ary[100005];

int main()
{
	int n, i, j;
	long long t, ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=0, ans=0; i<n; i=j)
	{
		for (j=i+1; j<n&&ary[j]>ary[j-1]; j++);
		t = j-i;
		ans += t*(t+1)/2;
	}
	printf("%lld\n", ans);
	return 0;
}