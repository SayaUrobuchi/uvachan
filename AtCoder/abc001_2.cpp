#include <iostream>
using namespace std;

int main()
{
	int n, ans;
	scanf("%d", &n);
	if (n < 100)
	{
		ans = 0;
	}
	else if (n <= 5000)
	{
		ans = n / 100;
	}
	else if (n <= 30000)
	{
		ans = n / 1000 + 50;
	}
	else if (n <= 70000)
	{
		ans = ((n / 1000) - 30) / 5 + 80;
	}
	else
	{
		ans = 89;
	}
	printf("%02d\n", ans);
	return 0;
}