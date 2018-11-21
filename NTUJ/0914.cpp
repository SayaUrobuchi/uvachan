#include <stdio.h>
#include <string.h>

int dp1[3005][3005], dp2[3005][3005], ch1[3], ch2[3];
char str[1000005];

int main()
{
	int cas, count, i, j, c, f, cnt1, cnt2, ans;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", str);
		memset(dp1, 1, sizeof(dp1));
		memset(dp2, 1, sizeof(dp2));
		dp1[0][0] = 3;
		dp2[0][0] = 3;
		cnt1 = 1;
		cnt2 = 1;
		ch1[0] = str[0]-'A';
		ch1[1] = (ch1[0]+1)%3;
		ch1[2] = (ch1[1]+1)%3;
		ch2[0] = str[0]-'A';
		ch2[1] = (ch2[0]+2)%3;
		ch2[2] = (ch2[1]+2)%3;
		for(i=1; str[i]; i++)
		{
			c = str[i]-'A';
			for(j=cnt1-1; j>=0; j--)
			{
				if(c == ch1[j%3])
				{
					if(dp1[i][j] > dp1[i-1][j] + 1)
					{
						dp1[i][j] = dp1[i-1][j] + 1;
					}
				}
				else if(c == ch1[(j+1)%3])
				{
					if(j != 0)
					{
						if(dp1[i][j-2] > dp1[i-1][j] + 1)
						{
							dp1[i][j-2] = dp1[i-1][j] + 1;
						}
					}
					if(dp1[i][j+1] > dp1[i-1][j] + 3)
					{
						dp1[i][j+1] = dp1[i-1][j] + 3;
						if(j+1 >= cnt1)
						{
							cnt1 = j+1+1;
						}
					}
				}
				else
				{
					if(j != 0 && dp1[i][j-1] > dp1[i-1][j] + 1)
					{
						dp1[i][j-1] = dp1[i-1][j] + 1;
					}
					if(j == 0 && dp2[i][j+1] > dp1[i-1][j] + 3)
					{
						dp2[i][j+1] = dp1[i-1][j] + 3;
						if(j+1 >= cnt2)
						{
							cnt2 = j+1+1;
						}
					}
				}
			}
			for(j=cnt2-1; j>=0; j--)
			{
				if(c == ch2[j%3])
				{
					if(dp2[i][j] > dp2[i-1][j] + 1)
					{
						dp2[i][j] = dp2[i-1][j] + 1;
					}
				}
				else if(c == ch2[(j+1)%3])
				{
					if(j != 0)
					{
						if(dp2[i][j-2] > dp2[i-1][j] + 1)
						{
							dp2[i][j-2] = dp2[i-1][j] + 1;
						}
					}
					if(dp2[i][j+1] > dp2[i-1][j] + 3)
					{
						dp2[i][j+1] = dp2[i-1][j] + 3;
						if(j+1 >= cnt2)
						{
							cnt2 = j+1+1;
						}
					}
				}
				else
				{
					if(j != 0 && dp2[i][j-1] > dp2[i-1][j] + 1)
					{
						dp2[i][j-1] = dp2[i-1][j] + 1;
					}
					if(j == 0 && dp1[i][j+1] > dp2[i-1][j] + 3)
					{
						dp1[i][j+1] = dp2[i-1][j] + 3;
						if(j+1 >= cnt1)
						{
							cnt1 = j+1+1;
						}
					}
				}
			}
		}
		f = i-1;
		for(i=0, ans=2147483647; i<cnt1; i++)
		{
			if(dp1[f][i] < ans)
			{
				ans = dp1[f][i];
			}
		}
		for(i=0; i<cnt2; i++)
		{
			if(dp2[f][i] < ans)
			{
				ans = dp2[f][i];
			}
		}
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}
