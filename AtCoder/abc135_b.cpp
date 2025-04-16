#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int cnt = 0;
	for (i=1; i<=n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t != i)
		{
			++cnt;
		}
	}
	puts(cnt <= 2 ? "YES" : "NO");
	return 0;
}
