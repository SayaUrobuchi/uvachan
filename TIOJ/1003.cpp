#include <stdio.h>

int recursion(int now)
{
	if(!now)
	{
		return 1;
	}
	return now + recursion(now-1);
}

int main()
{
	int a;
	scanf("%d", &a);
	printf("%d\n", recursion(a));
	scanf(" ");
	return 0;
}
