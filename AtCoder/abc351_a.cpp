#include <iostream>
using namespace std;

int main()
{
	int i;
	int ans = 0;
	for (i=0; i<9; i++)
	{
		int t;
		scanf("%d", &t);
		ans += t;
	}
	for (i=0; i<8; i++)
	{
		int t;
		scanf("%d", &t);
		ans -= t;
	}
	++ans;
	printf("%d\n", ans);
	return 0;
}
