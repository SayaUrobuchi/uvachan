#include <iostream>
using namespace std;

bool leap(int n)
{
	return (n % 400 == 0 || (n % 4 == 0 && n % 100));
}

int main()
{
	int a, b, i;
	scanf("%d%d", &a, &b);
	int ans = 0;
	for (i=a; i<=b&&i%400; i++)
	{
		ans += leap(i);
	}
	ans += 97 * (b/400 - i/400);
	for (i=max(i, b-b%400); i<=b; i++)
	{
		ans += leap(i);
	}
	printf("%d\n", ans);
	return 0;
}
