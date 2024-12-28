#include <iostream>
#include <algorithm>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, a, b, i;
	scanf("%d%d%d", &n, &a, &b);
	for (i=1; i<=n; i++)
	{
		ary[i] = i;
	}
	reverse(ary+a, ary+b+1);
	for (i=1; i<=n; i++)
	{
		printf("%d%c", ary[i], " \n"[i==n]);
	}
	return 0;
}
