#include <stdio.h>

int main()
{
	int count, n, t, i, ans,j;
	scanf("%d", &count);
	while(count--)
	{
		j=1;
		scanf("%d%d", &n, &ans);
		if(ans!=1)
		{
			j=0;
		}
		for(i=1; i<n; i++)
		{
			scanf("%d", &t);
			if(t!=1)
			{
				j=0;
			}
			ans ^= t;
		}
		if(j==0)
		{
			if(ans==0)
			{
				printf("Brother\n");
			}
			else
			{
				printf("John\n");
			}
		}
		else
		{
			if(ans!=0)
			{
				printf("Brother\n");
			}
			else
			{
				printf("John\n");
			}
		}
	}
	return 0;
}
