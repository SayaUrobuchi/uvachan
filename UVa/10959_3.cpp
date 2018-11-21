#include <stdio.h>
#include <string.h>

int map[1000][1000];

int main()
{
	int p, d, now, count, i, j, k, ctmp, ptmp, min;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &p, &d);
		for(i=0; i<p; i++)
		{
			for(j=0; j<p; j++)
			{
				map[i][j] = 0;
			}
		}
		while(d--)
		{
			scanf("%d%d", &i, &j);
			map[i][j] = 1;
			map[j][i] = 1;
		}
		for(i=1; i<p; i++)
		{
			for(k=0; k<p; k++)
			{
				ctmp = map[0][k];
				if(ctmp)
				{
					ctmp++;
					for(j=0; j<p; j++)
					{
						if(map[k][j])
						{
							if(!map[0][j] || ctmp < map[0][j])
							{
								map[0][j] = ctmp;
							}
						}
					}
				}
			}
		}
		for(i=1; i<p; i++)
		{
			printf("%d\n", map[0][i]);
		}
		if(count) printf("\n");
	}
	return 0;
}
