#include <iostream>
using namespace std;

const int N = 1000005;

int ary[N];

int bs(int l, int r, int a, int b)
{
	if (l > r || a >= b)
	{
		return 0;
	}
	int mid = ((l + r) >> 1);
	return (ary[mid] > a && ary[mid] < b)
		   + bs(l, mid-1, a, min(b, ary[mid]))
		   + bs(mid+1, r, max(a, ary[mid]), b);
}

int main()
{
	int n, m, a, b, i;
	scanf("%d%d%d%d%d", &n, &m, &a, &b, &ary[0]);
	for (i=1; i<=n; i++)
	{
		ary[i] = ((long long)ary[i-1] * a + b) % m;
	}
	printf("%d\n", bs(1, n, -1, 2147483647));
	return 0;
}
