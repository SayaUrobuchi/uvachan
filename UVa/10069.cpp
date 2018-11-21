#include <stdio.h>
#include <string.h>

int ary[102][101], num[102];
char str[10002], str2[102];

int main()
{
	int count, i, j, k, len;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%s", str, str2);
		len = strlen(str2);
		for(i=0; i<102; i++)
		{
			num[i] = 1;
		}
		memset(ary, 0, sizeof(ary));
		ary[0][0] = 1;
		for(i=0; str[i]; i++)
		{
			for(j=len-1; j>-1; j--)
			{
				if(str[i] == str2[j])
				{
					for(k=0; k<num[j]; k++)
					{
						ary[j+1][k] += ary[j][k];
						if(ary[j+1][k] > 999999999)
						{
							ary[j+1][k] -= 1000000000;
							ary[j+1][k+1]++;
						}
					}
					for(; ary[j+1][k]; k++)
					{
						if(ary[j+1][k] > 999999999)
						{
							ary[j+1][k] -= 1000000000;
							ary[j+1][k+1]++;
						}
					}
					num[j+1] = k;
				}
			}
		}
		printf("%d", ary[len][num[len]-1]);
		for(i=num[len]-2; i>-1; i--)
		{
			printf("%09d", ary[len][i]);
		}
		printf("\n");
	}
	return 0;
}
