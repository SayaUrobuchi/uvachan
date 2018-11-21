#include <stdio.h>
#include <string.h>

int ary[205][1005], carry[205];

int main()
{
	int n, i, j, k, temp, ans;
	while(scanf("%d", &n) == 1)
	{
		printf("For base %d the double-trouble number is\n", n);
		for(i=1; i<n; i++)
		{
			ary[i][0] = i;
		}
		memset(carry, 0, sizeof(carry));
		for(j=0; ; j++)
		{
			for(i=1; i<n; i++)
			{
				temp = (ary[i][j] << 1) + carry[i];
				ary[i][j+1] = temp % n;
				if(temp == ary[i][0])
				{
					ans = i;
					break;
				}
				carry[i] = temp / n;
			}
			if(i < n)
			{
				break;
			}
		}
		for(i=j; i>=0; i--)
		{
			printf("%d ", ary[ans][i]);
		}
		printf("\n");
	}
	return 0;
}
