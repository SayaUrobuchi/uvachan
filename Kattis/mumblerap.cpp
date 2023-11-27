#include <iostream>
using namespace std;

const int N = 1000005;

char s[N];

int main()
{
	int n, i, t, u, ans;
	fgets(s, sizeof(s), stdin);
	sscanf(s, "%d", &n);
	fgets(s, sizeof(s), stdin);
	for (i=0, ans=0, t=0; i<n; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			t = t * 10 + (s[i] - '0');
			ans = max(ans, t);
		}
		else
		{
			t = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
