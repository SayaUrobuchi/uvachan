#include <stdio.h>

int pro[12];

int main()
{
	int cas, s, i, now, temp;
	cas = 0;
	while(scanf("%d", &s) == 1)
	{
		if(s < 0)
		{
			break;
		}
		for(i=0; i<12; i++)
		{
			scanf("%d", &pro[i]);
		}
		printf("Case %d:\n", ++cas);
		for(i=0, now=s; i<12; i++)
		{
			scanf("%d", &temp);
			if(now >= temp)
			{
				printf("No problem! :D\n");
				now -= temp;
			}
			else
			{
				printf("No problem. :(\n");
			}
			now += pro[i];
		}
	}
	return 0;
}
