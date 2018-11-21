#include <stdio.h>
#include <string.h>

int ary1[26][65], ary2[26][65];
int num1[26], num2[26];
int dp[65][65], dp2[65][65];
char s1[100], s2[100], s3[100];

int main()
{
	int count, i, j, k, l, temp, temp2, len1, len2;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%s%s", s1, s2, s3);
		memset(dp, 0, sizeof(dp));
		memset(dp2, 0, sizeof(dp2));
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
		dp[0][0] = 1;
		for(i=0; s3[i]; i++)
		{
			temp = s3[i] - 97;
			for(j=0; j<num1[temp]; j++)
			{
				temp2 = ary1[temp][j];
				for(k=0; k<=len2; k++)
				{
					for(l=0; l<=temp2; l++)
					{
						dp2[temp2+1][k] += dp[l][k];
						if(dp2[temp2+1][k] >= 10007)
						{
							dp2[temp2+1][k] -= 10007;
						}
					}
				}
			}
			for(j=0; j<num2[temp]; j++)
			{
				temp2 = ary2[temp][j];
				for(k=0; k<=len1; k++)
				{
					for(l=0; l<=temp2; l++)
					{
						dp2[k][temp2+1] += dp[k][l];
						if(dp2[k][temp2+1] >= 10007)
						{
							dp2[k][temp2+1] -= 10007;
						}
					}
				}
			}
			memcpy(dp, dp2, sizeof(dp));
			memset(dp2, 0, sizeof(dp2));
		}
		for(i=0, temp=0; i<=len1; i++)
		{
			for(j=0; j<=len2; j++)
			{
				temp += dp[i][j];
				if(temp >= 10007)
				{
					temp -= 10007;
				}
			}
		}
		printf("%d\n", temp);
	}
	return 0;
}
