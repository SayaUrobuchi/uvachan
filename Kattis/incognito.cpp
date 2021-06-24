#include <iostream>
#include <algorithm>
using namespace std;

string ary[32];
char buf[1024];

int main()
{
	int count, n, i, j;
	long long ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%*s%s", buf);
			ary[i] = buf;
		}
		sort(ary, ary+n);
		for (i=0, ans=1; i<n; i=j)
		{
			for (j=i+1; j<n&&ary[i]==ary[j]; j++);
			ans *= (j-i+1);
		}
		printf("%lld\n", ans-1);
	}
	return 0;
}
