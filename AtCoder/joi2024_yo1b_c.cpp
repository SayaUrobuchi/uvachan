#include <iostream>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int n, i;
	scanf("%d%s", &n, s);
	int ans = 0;
	for (i=0; i<n; i++)
	{
		if (s[i] == 'o')
		{
			++ans;
		}
		else
		{
			ans += 2;
		}
	}
	printf("%d\n", ans);
	return 0;
}
