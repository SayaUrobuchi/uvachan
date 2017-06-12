#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEPTH 12

int tbl[DEPTH];
char buf[1005];

void recursion(int multi, int degree)
{
	int temp;
	while(scanf("%s", buf) == 1)
	{
		if(!strcmp(buf, "END"))
		{
			return;
		}
		if(!strcmp(buf, "LOOP"))
		{
			scanf("%s", buf);
			if(buf[0] == 'n')
			{
				recursion(multi, degree+1);
			}
			else
			{
				sscanf(buf, "%d", &temp);
				recursion(multi*temp, degree);
			}
		}
		else
		{
			scanf("%s", buf);
			sscanf(buf, "%d", &temp);
			tbl[degree] += multi * temp;
		}
	}
}

int main()
{
	int cas, count, i, f;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", buf);
		memset(tbl, 0, sizeof(tbl));
		recursion(1, 0);
		printf("Program #%d\n", ++cas);
		printf("Runtime = ");
		for(i=DEPTH-1, f=0; i>=0; i--)
		{
			if(tbl[i])
			{
				if(f)
				{
					printf("+");
				}
				if(tbl[i] > 1 || !i)
				{
					printf("%d", tbl[i]);
					if(i)
					{
						printf("*");
					}
				}
				if(i)
				{
					printf("n");
					if(i > 1)
					{
						printf("^%d", i);
					}
				}
				f = 1;
			}
			else if(!i && !f)
			{
				printf("0");
			}
		}
		printf("\n\n");
	}
	return 0;
}
