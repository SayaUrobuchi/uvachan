#include <stdio.h>

int main()
{
	int m, s, t;
	while(scanf("%d%d", &m, &s) == 2)
	{
		t = m*60 + s;
		if(t < 7*60+30 || t >= 17*60)
		{
			printf("Off School\n");
		}
		else
		{
			printf("At School\n");
		}
	}
	return 0;
}
