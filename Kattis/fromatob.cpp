#include <iostream>

int main()
{
	int a, b, ans;
	while (scanf("%d%d", &a, &b) == 2)
	{
		ans = 0;
		while (a > b)
		{
			if (a & 1)
			{
				++a;
			}
			else
			{
				a >>= 1;
			}
			++ans;
		}
		printf("%d\n", b-a+ans);
	}
	return 0;
}

