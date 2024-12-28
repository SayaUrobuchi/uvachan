#include <iostream>
using namespace std;

int main()
{
	int i;
	int a, b;
	scanf("%d%d", &a, &b);
	int l = 1;
	for (i=0; i<b; i++)
	{
		l *= a;
	}
	int r = 1;
	for (i=0; i<a; i++)
	{
		r *= b;
	}
	int ans = l + r;
	printf("%d\n", ans);
	return 0;
}
