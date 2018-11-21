#include <stdio.h>

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		puts(b-a >= 7 ? "PASS!" : "FAIL! You see see you!");
	}
	return 0;
}
