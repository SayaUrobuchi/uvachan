#include <stdio.h>
#include <string.h>

int tbl[60001];

int main()
{
	int count, n, i, j, temp, temp2;
	for(i=0; i<60001; i++)
	{
		tbl[i] = -1;
	}
	for(i=0; i<230; i++)
	{
		tbl[i*i] = i;
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<230; i++)
		{
			temp = i * i;
			if(temp <= n)
			{
				for(j=i; j<230; j++)
				{
					if(1)
					{
						temp2 = j * j;
						if(temp + temp2 <= n)
						{
							if(tbl[n-(temp+temp2)] >= j)
							{
								printf("%d %d %d\n", i, j, tbl[n-(temp+temp2)]);
								break;
							}
						}
					}
				}
				if(j < 230)
				{
					break;
				}
			}
		}
		if(i == 230)
		{
			printf("-1\n");
		}
	}
	return 0;
}
