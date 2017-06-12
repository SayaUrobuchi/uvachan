#include <stdio.h>

long long matrix[101][101];

int main()
{
	int cas, count, n, i, j, flag;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%*s%*s%d", &n);
		for(i=0, flag=1; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%lld", &matrix[i][j]);
				flag &= (matrix[i][j] >= 0);
			}
		}
		if(flag)
		{
			for(i=0; i<n; i++)
			{
				if(n < i + i + 1)
				{
					break;
				}
				for(j=0; j<n; j++)
				{
					if(matrix[i][j] != matrix[n-i-1][n-j-1])
					{
						flag = 0;
						break;
					}
				}
				if(j < n)
				{
					break;
				}
			}
		}
		if(flag)
		{
			printf("Test #%d: Symmetric.\n", ++cas);
		}
		else
		{
			printf("Test #%d: Non-symmetric.\n", ++cas);
		}
	}
	return 0;
}
