#include <stdio.h>

int tbl[51];

int main()
{
	int n, i, j, c;
	scanf("%d", &n);
	for(i=1, j=0, c=0; i<n; j++)
	{
		if(j == n)
		{
			j = 0;
		}
		if(!tbl[j])
		{
			c++;
			if(c == 2)
			{
				c = 0;
				tbl[j] = 1;
				i++;
			}
		}
	}
	for(i=0; i<n; i++)
	{
		if(!tbl[i])
		{
			break;
		}
	}
	printf("%d\n", i+1);
	scanf(" ");
	return 0;
}
