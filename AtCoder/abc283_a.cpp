#include <iostream>
using namespace std;

int main()
{
	int a, b, i;
	scanf("%d%d", &a, &b);
	int ans = 1;
	for (i=0; i<b; i++)
	{
		ans *= a;
	}
	printf("%d\n", ans);
	return 0;
}
