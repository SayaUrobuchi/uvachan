#include <stdio.h>

int main()
{
	int count, a, b, c;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &a, &b, &c);
		if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
		{
			puts("yes");
		}
		else
		{
			puts("no");
		}
	}
	return 0;
}
