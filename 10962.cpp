#include <stdio.h>

int tarea[3000][2];

int main()
{
	int count, n, m, i, j, p, q, r, s, time;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d", &n, &m, &r, &s);
		time = 0;
		i = 0;
		tarea[0][0] = tarea[0][1] = -1;
		while(r--)
		{
			scanf("%d%d", &p, &q);
			time += q * m;
			if(tarea[i][1] < time)
			{
				tarea[++i][0] = time;
				tarea[i][1] = time + (p-q) * n;
			}
			else
			{
				tarea[i][1] += (p-q) * n;
			}
		}
		j = 1;
		while(s--)
		{
			scanf("%d", &time);
			time *= n * m;
			for(; j<=i; j++)
			{
				/*printf("%d %d\n", tarea[j][0], tarea[j][1]);*/
				if(tarea[j][1] >= time)
				{
					break;
				}
			}
			if(j > i)
			{
				printf("clear\n");
			}
			else if(tarea[j][0] <= time && time <= tarea[j][1])
			{
				printf("full\n");
			}
			else
			{
				printf("clear\n");
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
