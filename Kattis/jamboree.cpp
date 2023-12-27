#include <iostream>
#include <algorithm>
using namespace std;

const int N = 205;

int ary[N];

int main()
{
	int n, m, i, dup, worst;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	dup = max(0, n - m);
	for (i=0, worst=0; i<dup; i++)
	{
		worst = max(worst, ary[i]+ary[(dup<<1)-i-1]);
	}
	for (i=(dup<<1); i<n; i++)
	{
		worst = max(worst, ary[i]);
	}
	printf("%d\n", worst);
	return 0;
}
