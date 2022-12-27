#include <iostream>
#include <algorithm>
using namespace std;

char s[128], buf[128];

int main()
{
	int n, i, a, b;
	long long ans;
	while (scanf("%s", s) == 1)
	{
		for (n=0; s[n]; ++n);
		sort(s, s+n);
		ans = 0;
		do
		{
			if (s[0] != '0')
			{
				for (i=1; i<n; i++)
				{
					if (s[i] != '0')
					{
						sprintf(buf, "%%%dd%%d", i);
						sscanf(s, buf, &a, &b);
						ans = max(ans, (long long)a * b);
					}
				}
			}
		}while(next_permutation(s, s+n));
		printf("%lld\n", ans);
	}
	return 0;
}

