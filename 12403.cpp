#include <stdio.h>

char buf[1024];

int main()
{
	int count, a, ac;
	scanf("%d", &count);
	ac = 0;
	while(count--)
	{
		scanf("%s", buf);
		if(*buf == 'd')
		{
			scanf("%d", &a);
			ac += a;
		}
		else
		{
			printf("%d\n", ac);
		}
	}
	return 0;
}
