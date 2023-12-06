#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1048576;

int ary[N];

int main()
{
	int n, t, i, sum;
	scanf("%d%d", &t, &n);
	t *= 60;
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	for (i=0, sum=0; i<n&&sum+ary[i]<=t; i++)
	{
		sum += ary[i];
	}
	printf("%d\n", sum);
	return 0;
}
