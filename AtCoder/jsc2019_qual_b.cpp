#include <iostream>
using namespace std;

const int N = 2005;
const int M = 1e9 + 7;

int ary[N];

void add(int &a, const long long &b)
{
	a = (a + b) % M;
}

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		for (j=0; j<i; j++)
		{
			if (ary[j] > ary[i])
			{
				add(ans, m*1LL*(m+1)/2);
			}
			else if (ary[j] < ary[i])
			{
				add(ans, m*1LL*(m-1)/2);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
