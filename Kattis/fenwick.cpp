#include <iostream>
using namespace std;

const int N = 5000005;

long long bit[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		char cmd;
		int a, b;
		scanf(" %c", &cmd);
		if (cmd == '+')
		{
			scanf("%d%d", &a, &b);
			for (++a; a<=n; a+=(a&-a))
			{
				bit[a] += b;
			}
		}
		else
		{
			scanf("%d", &a);
			long long ans = 0;
			for (; a; a-=(a&-a))
			{
				ans += bit[a];
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
