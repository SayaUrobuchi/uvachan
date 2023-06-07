#include <iostream>
#include <algorithm>
using namespace std;

const int M = 3;

long long ary[M];

bool recurs(int depth, long long n, long long m)
{
	if (n < 0 || m < 0)
	{
		return false;
	}
	if (depth == 3)
	{
		return true;
	}
	if (n == 0 || m == 0)
	{
		return false;
	}
	long long x = (ary[depth] + (m - 1)) / m;
	if (recurs(depth+1, n-x, m))
	{
		return true;
	}
	long long y = (ary[depth] + (n - 1)) / n;
	if (recurs(depth+1, n, m-y))
	{
		return true;
	}
	return false;
}

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<M; i++)
	{
		scanf("%lld", &ary[i]);
	}
	sort(ary, ary+M);
	bool ans = false;
	do
	{
		ans = recurs(0, n, m);
	}while (!ans && next_permutation(ary, ary+M));
	puts(ans ? "Yes" : "No");
	return 0;
}
