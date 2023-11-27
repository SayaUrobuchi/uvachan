#include <iostream>
using namespace std;

char s[1005], ans[1005];

int main()
{
	int n, i, t;
	scanf("%d", &n);
	for (i=0, t=0; i<n; i++)
	{
		scanf("%s", s);
		if (*s >= 'A' && *s <= 'Z')
		{
			ans[t] = *s;
			++t;
		}
	}
	ans[t] = 0;
	puts(ans);
	return 0;
}
