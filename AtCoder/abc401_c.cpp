#include <iostream>
using namespace std;

const int N = 1000005;
const int MOD = 1e9;

int ary[N], bry[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		ary[i] = 1;
		bry[i] = (bry[i-1] + ary[i]) % MOD;
	}
	for (; i<=n; i++)
	{
		ary[i] = (bry[i-1] - bry[i-m-1] + MOD) % MOD;
		bry[i] = (bry[i-1] + ary[i]) % MOD;
	}
	printf("%d\n", ary[n]);
	return 0;
}
