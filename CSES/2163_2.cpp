#include <iostream>
using namespace std;

const int N = 200005;

int bit[N];

int main()
{
	int n, m, i, j, k, u;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		bit[i] = (i & -i);
	}
	for (u=0; (1<<u)<=n; u++);
	--u;
	for (i=n, j=0; i; i--)
	{
		j = (j+m) % i;
		int t = j + 1;
		// find t
		int pos = 0;
		for (k=(1<<u); k; k>>=1)
		{
			if (pos+k <= n && bit[pos+k] < t)
			{
				pos += k;
				t -= bit[pos];
			}
		}
		// remove pos
		for (k=pos+1; k<=n; k+=(k&-k))
		{
			--bit[k];
		}
		printf("%d%c", pos+1, (i==1)?'\n':' ');
	}
	return 0;
}
