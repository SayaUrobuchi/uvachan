/*
	ID: sa072682
	LANG: C
	TASK: preface
*/
#include <stdio.h>

int dp[3500][9], temp[3];
char hash[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

void calc(int now)
{
	temp[0] = temp[1] = temp[2] = 0;
	if(!now)
	{
		return;
	}
	if(now < 4)
	{
		temp[0] = now;
	}
	else
	{
		if(now == 9)
		{
			temp[0] = temp[2] = 1;
		}
		else
		{
			temp[1] = 1;
			if(now == 4 || now == 6)
			{
				temp[0] = 1;
			}
			else if(now != 5)
			{
				temp[0] += now - 5;
			}
		}
	}
}

int main()
{
	int n, i, j, k;
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
	dp[1][0] = 1;
	for(i=2; i<3500; i++)
	{
		for(j=0; j<7; j++)
		{
			dp[i][j] = dp[i-1][j];
		}
		for(j=0, k=i; k; j+=2, k/=10)
		{
			calc(k%10);
			dp[i][j] += temp[0];
			dp[i][j+1] += temp[1];
			dp[i][j+2] += temp[2];
		}
	}
	scanf("%d", &n);
	for(i=0; i<7; i++)
	{
		if(!dp[n][i])
		{
			break;
		}
		printf("%c %d\n", hash[i], dp[n][i]);
	}
	scanf(" ");
	return 0;
}
