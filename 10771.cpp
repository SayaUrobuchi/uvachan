#include <stdio.h>

int main()
{
	int n, m, o;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(!n && !m && !o)
		{
			break;
		}
		if(m % 2)
		{
			printf("Keka\n");
		}
		else
		{
			printf("Gared\n");
		}
	}
	return 0;
}
