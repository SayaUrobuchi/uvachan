#include <iostream>

int main()
{
	int a, b, c, ans;
	while (scanf("%d%d", &a, &b) == 2)
	{
		if (a == 0 && b == 0)
		{
			break;
		}
		for (c=0, ans=0; a||b; a/=10, b/=10)
		{
			c = (c + a%10 + b%10) / 10;
			if (c)
			{
				++ans;
			}
		}
		if (ans == 0)
		{
			puts("No carry operation.");
		}
		else
		{
			printf("%d carry operation%s.\n", ans, ans!=1?"s":"");
		}
	}
	return 0;
}
