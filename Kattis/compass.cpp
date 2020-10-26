#include <iostream>

int main()
{
	int n, m, t;
	while (scanf("%d%d", &n, &m) == 2)
	{
		t = (m+360-n) % 360;
		if (t <= 180)
		{
			printf("%d\n", t);
		}
		else
		{
			printf("%d\n", t-360);
		}
	}
	return 0;
}
