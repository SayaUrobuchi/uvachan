#include <iostream>
#include <bitset>
using namespace std;

const int PN = 5761455;
const int N = 100000005;

int prime[PN+5];
bitset<N> tbl;

int main()
{
	int n, m, i, j;
	int pn = 0;
	tbl.set(1);
	scanf("%d%d", &n, &m);
	for (i=2; i<=n; i++)
	{
		if (!tbl[i])
		{
			prime[pn] = i;
			++pn;
		}
		for (j=0; j<pn&&i*prime[j]<=n; j++)
		{
			tbl.set(i*prime[j]);
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
	printf("%d\n", pn);
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		printf("%d\n", !tbl.test(t));
	}
	return 0;
}
