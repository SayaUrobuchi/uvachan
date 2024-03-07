#include <iostream>
using namespace std;

int main()
{
	int n, i;
	bool appear[7] = {};
	scanf("%d", &n);
	bool gg = false;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		if (appear[t])
		{
			gg = true;
		}
		appear[t] = true;
	}
	int a = 1 * !gg;
	int b = 1;
	for (; i<4; i++)
	{
		int t = 6 - i;
		if (gg)
		{
			t = 0;
		}
		a *= t;
		b *= 6;
	}
	printf("%d %d\n", a, b-a);
	return 0;
}