#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int mx = -1e9;
	int ans = 0;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t >= mx)
		{
			++ans;
			mx = t;
		}
	}
	printf("%d\n", ans);
	return 0;
}
