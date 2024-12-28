#include <iostream>
using namespace std;

int main()
{
	int i;
	int ans;
	for (i=1; i<=5; i++)
	{
		int t;
		scanf("%d", &t);
		if (!t)
		{
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}
