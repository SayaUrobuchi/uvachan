#include <stdio.h>
#include <string.h>

int flag;
char str[101][31], str2[101][31];
int lcs[101][101];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

void backtracing(int i, int j)
{
	if(lcs[i][j])
	{
		if(!strcmp(str[i-1], str2[j-1]))
		{
			backtracing(i-1, j-1);
			if(flag)
			{
				printf(" %s", str[i-1]);
			}
			else
			{
				printf("%s", str[i-1]);
			}
			flag = 1;
		}
		else
		{
			if(lcs[i-1][j] == lcs[i][j])
			{
				backtracing(i-1, j);
			}
			else
			{
				backtracing(i, j-1);
			}
		}
	}
}

int main()
{
	int n, m, i, j;
	n = 0;
	while(scanf("%s", str[n]) == 1)
	{
		if(str[n][0] == '#')
		{
			m = 0;
			while(scanf("%s", &str2[m]) == 1)
			{
				if(str2[m][0] == '#')
				{
					break;
				}
				m++;
			}
			for(i=0; i<n; i++)
			{
				for(j=0; j<m; j++)
				{
					if(!strcmp(str[i], str2[j]))
					{
						lcs[i+1][j+1] = lcs[i][j] + 1;
					}
					else
					{
						lcs[i+1][j+1] = max(lcs[i][j+1], lcs[i+1][j]);
					}
				}
			}
			flag = 0;
			backtracing(i, j);
			printf("\n");
			n = 0;
		}
		else
		{
			n++;
		}
	}
	return 0;
}
