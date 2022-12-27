#include <iostream>
using namespace std;

int main()
{
	int count, a, b, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &a, &b);
		for (ans=1, --b; --a; ans=(ans<<1)|(b&1), b>>=1);
		printf("%d\n", ans);
	}
	return 0;
}