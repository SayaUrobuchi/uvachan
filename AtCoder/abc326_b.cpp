#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans = -1;
	while (ans < 0)
	{
		int t = n;
		int a = t % 10;
		t /= 10;
		int b = t % 10;
		t /= 10;
		int c = t;
		if (a == b * c)
		{
			ans = n;
			break;
		}
		++n;
	}
	printf("%d\n", ans);
	return 0;
}
