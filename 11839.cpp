#include <stdio.h>

int main()
{
	int n, i, j, t, a[5];
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4]);
			t = -1;
			for(j=0; j<5; j++)
			{
				if(a[j] <= 127)
				{
					if(t != -1)
					{
						break;
					}
					t = j;
				}
			}
			if(j < 5 || t == -1)
			{
				printf("*\n");
			}
			else
			{
				printf("%c\n", 'A'+t);
			}
		}
	}
	return 0;
}
