#include <stdio.h>
#include <string.h>

int tbl[16][2], dp[16][4096], last[16][4096], self[16][4096], times[13], n, flag;
char str[1000];

int trans(char now)
{
	return now == '+' ? 1 : 0;
}

int backtracing(int now, int loc)
{
	if(now)
	{
		backtracing(now-1, last[now][loc]);
	}
	if(self[now][loc])
	{
		if(flag)
		{
			flag = 0;
			printf(" ");
		}
		printf("%c", now+65);
	}
}

int main()
{
	int i, j, chk, temp;
	times[0] = 1;
	for(i=1; i<13; i++)
	{
		times[i] = times[i-1] * 2;
	}
	while(gets(str))
	{		
		memset(tbl, 0, sizeof(tbl));
		memset(dp, 0, sizeof(dp));
		n = 0;
		do
		{
			if(!strcmp(str, "."))
			{
				break;
			}
			for(i=0; str[i]!=';'; i+=2)
			{
				tbl[str[i+1]-65][trans(str[i])] |= times[n];
			}
			n++;
		}while(gets(str));
		dp[0][tbl[0][1]] = 1;
		self[0][tbl[0][1]] = 1;
		dp[0][tbl[0][0]] = 1;
		self[0][tbl[0][0]] = 0;
		chk = times[n];
		if(!dp[0][chk-1])
		{
			for(i=1; i<16; i++)
			{
				for(j=0; j<chk; j++)
				{
					if(dp[i-1][j])
					{
						dp[i][temp=(j|tbl[i][1])] = 1;
						last[i][temp] = j;
						self[i][temp] = 1;
						dp[i][temp=(j|tbl[i][0])] = 1;
						last[i][temp] = j;
						self[i][temp] = 0;
					}
				}
				if(dp[i][chk-1])
				{
					i++;
					break;
				}
			}
		}
		else
		{
			i = 1;
		}
		if(dp[i-1][chk-1])
		{
			printf("Toppings:");
			flag = 1;
			backtracing(i-1, chk-1);
			printf("\n");
		}
		else
		{
			printf("No pizza can satisfy these requests.\n");
		}
	}
	return 0;
}
