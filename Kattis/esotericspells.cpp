#include <iostream>
using namespace std;

const int N = 105;

long long ary[N], bry[N];

int main()
{
	int count, n, i, j;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%lld", &ary[i]);
			bry[i] = 0;
		}
		long long ans = 0;
		for (i=62; i>=0; i--)
		{
			for (j=0; j<n; j++)
			{
				if ((bry[j] | (1LL << i)) <= ary[j])
				{
					bry[j] |= (1LL << i);
					ans |= (1LL << i);
					break;
				}
			}
		}
		printf("%lld\n%lld", ans, bry[0]);
		for (i=1; i<n; i++)
		{
			printf(" %lld", bry[i]);
		}
		puts("");
	}
	return 0;
}
