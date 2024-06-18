#include <iostream>
using namespace std;

char s[105];

int main()
{
	int n, i;
	scanf("%d%s", &n, s);
	if (n & 1)
	{
		puts("-1");
	}
	else
	{
		int ans = 0;
		int half = (n >> 1);
		for (i=0; i+half<n; i++)
		{
			ans += (s[i] != s[i+half]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
