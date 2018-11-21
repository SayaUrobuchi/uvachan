#include <stdio.h>
#include <stdlib.h>

char cur[11], bir[11];

int main()
{
	int cas, count, cd, cm, cy, bd, bm, by, old;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%s", cur, bir);
		cur[2] = 0;
		cur[5] = 0;
		bir[2] = 0;
		bir[5] = 0;
		cd = atoi(cur);
		cm = atoi(cur+3);
		cy = atoi(cur+6);
		bd = atoi(bir);
		bm = atoi(bir+3);
		by = atoi(bir+6);
		if(cy < by)
		{
			printf("Case #%d: Invalid birth date\n", ++cas);
		}
		else if(cy == by)
		{
            if(cm > bm)
			{
				printf("Case #%d: 0\n", ++cas);
			}
			else if(cm == bm)
			{
				if(cd < bd)
				{
					printf("Case #%d: Invalid birth date\n", ++cas);
				}
				else
				{
                    printf("Case #%d: 0\n", ++cas);
				}
			}
			else
			{
                printf("Case #%d: Invalid birth date\n", ++cas);
			}
		}
		else
		{
			old = cy - by - 1;
			if(cm > bm)
			{
				old++;
				if(old > 130)
				{
					printf("Case #%d: Check birth date\n", ++cas);
				}
				else
				{
					printf("Case #%d: %d\n", ++cas, old);
				}
			}
			else if(cm == bm)
			{
				if(cd < bd)
				{
                    if(old > 130)
					{
						printf("Case #%d: Check birth date\n", ++cas);
					}
					else
					{
						printf("Case #%d: %d\n", ++cas, old);
					}
				}
				else
				{
					old++;
					if(old > 130)
					{
						printf("Case #%d: Check birth date\n", ++cas);
					}
					else
					{
						printf("Case #%d: %d\n", ++cas, old);
					}
				}
			}
			else
			{
                if(old > 130)
				{
					printf("Case #%d: Check birth date\n", ++cas);
				}
				else
				{
					printf("Case #%d: %d\n", ++cas, old);
				}
			}
		}
	}
	return 0;
}
