#include <stdio.h>
#include <string.h>

int tbl[3];
char str[1005];

int main()
{
	int cas, count, i, res;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", str);
		if(str[1] == 0)
		{
			printf("Case %d: S\n", ++cas);
		}
		else
		{
			memset(tbl, 0, sizeof(tbl));
			for(i=0, res=0; str[i]; i++)
			{
				res += (str[i] -= '0');
				tbl[str[i]%3]++;
			}
			if(tbl[res%3] == 0)
			{
				printf("Case %d: T\n", ++cas);
			}
			else
			{
				tbl[res%3]--;
				if(tbl[0] % 2)
				{
					printf("Case %d: T\n", ++cas);
				}
				else
				{
					printf("Case %d: S\n", ++cas);
				}
			}
		}
	}
	return 0;
}
