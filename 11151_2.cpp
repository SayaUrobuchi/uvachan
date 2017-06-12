#include <stdio.h>
#include <string.h>

int lcs[1001][1001];

int main()
{
	int n, len, i, j;
	char s1[1001], s2[1001];
	scanf("%d", &n);
	gets(s1);
	for(i=0; i<1001; i++)
	{
		lcs[0][i] = 0;
		lcs[i][0] = 0;
	}
	while(n--)
	{
		gets(s1);
		len = strlen(s1);
		if(!len) printf("0\n");
		else
		{
			for(i=0, j=len - 1; i<len; i++, j--)
			{
				s2[j] = s1[i];
			}
			for(i=1, len++; i<len; i++)
			{
				for(j=1; j<len; j++)
				{
					if(s1[i-1] == s2[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
					else
					{
						lcs[i][j] = lcs[i-1][j];
						if(lcs[i][j-1] > lcs[i][j]) lcs[i][j] = lcs[i][j-1];
					}
				}
			}
			printf("%d\n", lcs[len-1][len-1]);
		}
	}
	return 0;
}
