#include <iostream>
using namespace std;

int main()
{
	int n, i, cur, tar;
	scanf("%d%d%d", &n, &cur, &tar);
	int ans;
	bool found = false;
	for (i=1; i<=n; i++)
	{
		int t;
		scanf("%d", &t);
		if (cur + t >= tar && !found)
		{
			ans = i;
			found = true;
		}
	}
	printf("%d\n", ans);
	return 0;
}
