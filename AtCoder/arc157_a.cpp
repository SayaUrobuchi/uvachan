#include <iostream>
using namespace std;

int main()
{
	int n, a, b, c, d;
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	bool res = true;
	if (a)
	{
		if (d && !b && !c)
		{
			res = false;
		}
	}
	if (d)
	{
		if (a && !b && !c)
		{
			res = false;
		}
	}
	if (abs(b-c) > 1)
	{
		res = false;
	}
	puts(res ? "Yes" : "No");
	return 0;
}