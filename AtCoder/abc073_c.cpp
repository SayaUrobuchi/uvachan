#include <iostream>
#include <algorithm>
using namespace std;

int ary[100005];

int main()
{
	int n, i, j, ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	for (i=0, ans=0; i<n; i=j)
	{
		for (j=i+1; j<n&&ary[i]==ary[j]; j++);
		ans += (j-i) & 1;
	}
	printf("%d\n", ans);
	return 0;
}
