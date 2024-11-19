#include <iostream>
using namespace std;

const int N = 1000005;
const int M = 10007;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	ary[3] = 1;
	for (i=4; i<=n; i++)
	{
		ary[i] = (ary[i-1] + ary[i-2] + ary[i-3]) % M;
	}
	printf("%d\n", ary[n]);
	return 0;
}
