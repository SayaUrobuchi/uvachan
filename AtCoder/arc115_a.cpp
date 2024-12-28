#include <iostream>
using namespace std;

const int N = 32;

char s[N];

int main()
{
	int n, m, i, j;
	int cnt[2] = {};
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", s);
		int c = 0;
		for (j=0; j<m; j++)
		{
			c += s[j] - '0';
		}
		++cnt[c & 1];
	}
	printf("%lld\n", cnt[0]*1LL*cnt[1]);
	return 0;
}
