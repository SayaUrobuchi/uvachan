#include <iostream>
using namespace std;

int main()
{
	int a, b, c, i, ans;
	scanf("%d%d%d", &a, &b, &c);
	for (i=0, ans=0; i<a; i++)
	{
		int t;
		scanf("%d", &t);
		ans += (t+14 <= b+c);
	}
	printf("%d\n", ans);
	return 0;
}
