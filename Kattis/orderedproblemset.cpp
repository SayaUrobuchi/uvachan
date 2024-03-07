#include <iostream>
using namespace std;

const int N = 55;

int ary[N];

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	bool ans = false;
	for (i=2; i<=n; i++)
	{
		if (n % i == 0)
		{
			int t = n / i;
			int last = -1;
			bool ok = true;
			for (j=0; j<n&&ok; j+=t)
			{
				int nxt = -1;
				for (k=j; k<j+t&&ok; k++)
				{
					if (ary[k] < last)
					{
						ok = false;
					}
					nxt = max(nxt, ary[k]);
				}
				last = nxt;
			}
			if (ok)
			{
				printf("%d\n", i);
				ans = true;
			}
		}
	}
	if (!ans)
	{
		puts("-1");
	}
	return 0;
}