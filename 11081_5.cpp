#include <stdio.h>
#include <string.h>

int ary1[26][65], ary2[26][65];
int num1[26], num2[26];
int dp[65][65];
int tbl1[65][65], tbl2[65][65];
char s1[100], s2[100], s3[100];

int main()
{
	int count, i, j, k, temp, temp2, len1, len2;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%s%s", s1, s2, s3);
		memset(dp, 0, sizeof(dp));
		memset(num1, 0, sizeof(num1));
		memset(num2, 0, sizeof(num2));
		for(i=0; s1[i]; i++)
		{
			temp = s1[i] - 97;
			ary1[temp][num1[temp]++] = i;
		}
		len1 = i;
		for(i=0; s2[i]; i++)
		{
			temp = s2[i] - 97;
			ary2[temp][num2[temp]++] = i;
		}
		len2 = i;
		memset(tbl1, 0, sizeof(tbl1));
		memset(tbl2, 0, sizeof(tbl2));
		for(i=0; i<=len1; i++)
		{
			tbl1[i][0] = 1;
		}
		for(i=0; i<=len2; i++)
		{
			tbl2[0][i] = 1;
		}
		for(i=0; s3[i]; i++)
		{
			temp = s3[i] - 97;
			for(j=0; j<num1[temp]; j++)
			{
				temp2 = ary1[temp][j];
				for(k=0; k<=len2; k++)
				{
					dp[temp2+1][k] += tbl1[temp2][k];
					if(dp[temp2+1][k] >= 1073741823)
					{
						dp[temp2+1][k] %= 10007;
					}
				}
			}
			for(j=0; j<num2[temp]; j++)
			{
				temp2 = ary2[temp][j];
				for(k=0; k<=len1; k++)
				{
					dp[k][temp2+1] += tbl2[k][temp2];
					if(dp[k][temp2+1] >= 1073741823)
					{
						dp[k][temp2+1] %= 10007;
					}
				}
			}
			for(k=0; k<=len2; k++)
			{
				tbl1[0][k] = dp[0][k];
			}
			for(j=1; j<=len1; j++)
			{
				for(k=0; k<=len2; k++)
				{
					tbl1[j][k] = dp[j][k] + tbl1[j-1][k];
					if(tbl1[j][k] >= 1073741823)
					{
						tbl1[j][k] %= 10007;
					}
				}
			}
			for(k=0; k<=len1; k++)
			{
				tbl2[k][0] = dp[k][0];
			}
			for(j=1; j<=len2; j++)
			{
				for(k=0; k<=len1; k++)
				{
					tbl2[k][j] = dp[k][j] + tbl2[k][j-1];
					if(tbl2[k][j] >= 1073741823)
					{
						tbl2[k][j] %= 10007;
					}
				}
			}
			memset(dp, 0, sizeof(dp));
		}
		for(i=0, temp=0; i<=len2; i++)
		{
			temp += tbl1[len1][i];
			if(temp >= 1073741823)
			{
				temp %= 10007;
			}
		}
		printf("%d\n", temp%10007);
	}
	return 0;
}
