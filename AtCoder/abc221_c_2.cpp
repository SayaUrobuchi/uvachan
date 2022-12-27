#include <iostream>
#include <algorithm>
using namespace std;

char s[128], buf[128];

int main()
{
	int n, i, j, a, b;
	long long ans;
	while (scanf("%s", s) == 1)
	{
		for (n=0; s[n]; ++n);
		sort(s, s+n, greater<char>());
		for (i=1, ans=0; i<(1<<n); i++)
		{
			for (a=0, b=0, j=0; j<n; j++)
			{
				if (i & (1<<j))
				{
					a = a*10 + (s[j]-'0');
				}
				else
				{
					b = b*10 + (s[j]-'0');
				}
			}
			ans = max(ans, (long long)a*b);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

