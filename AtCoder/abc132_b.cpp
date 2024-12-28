#include <iostream>
using namespace std;

const int N = 32;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	int ans = 0;
	for (i=1; i+1<n; i++)
	{
		bool res = ary[i] > min(ary[i-1], ary[i+1]);
		res = (res && ary[i] < max(ary[i-1], ary[i+1]));
		ans += res;
	}
	printf("%d\n", ans);
	return 0;
}
