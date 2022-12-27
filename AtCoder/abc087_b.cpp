#include <iostream>
using namespace std;

int main()
{
	int a, b, c, x, i, j, t, u, v, ans;
	scanf("%d%d%d%d", &a, &b, &c, &x);
	for (i=0, t=0, ans=0; i<=a&&t<=x; i++, t+=500)
	{
		for (j=0, u=t; j<=b&&u<=x; j++, u+=100)
		{
			v = x - u;
			if (v % 50 == 0 && v <= c * 50)
			{
				++ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}