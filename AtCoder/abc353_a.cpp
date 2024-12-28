#include <iostream>
using namespace std;

int main()
{
	int n, i;
	int first;
	scanf("%d%d", &n, &first);
	bool found = false;
	int ans = -1;
	for (i=2; i<=n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t > first && !found)
		{
			found = true;
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}
