#include <iostream>
using namespace std;

int main()
{
	int n, ans;
	while (scanf("%d", &n) == 1)
	{
		if (n <= 125)
		{
			ans = 4;
		}
		else if (n <= 211)
		{
			ans = 6;
		}
		else
		{
			ans = 8;
		}
		printf("%d\n", ans);
	}
	return 0;
}

