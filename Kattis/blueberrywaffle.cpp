#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int t = (b * 180 / a) % 360;
	if (t < 90 || t >= 270)
	{
		puts("up");
	}
	else
	{
		puts("down");
	}
	return 0;
}
