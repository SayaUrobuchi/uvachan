#include <stdio.h>

int px1[1000], px2[1000], py1[1000], py2[1000];

int main()
{
	int count, n, m, i, j, x, y, best;
	double max, temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d%d", &px1[i], &py1[i], &px2[i], &py2[i]);
			if(px1[i] > px2[i])
			{
				m = px1[i];
				px1[i] = px2[i];
				px2[i] = m;
				m = py1[i];
				py1[i] = py2[i];
				py2[i] = m;
			}
		}
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &x, &y);
			for(; ; )
			{
				for(j=0, max=-1.0; j<n; j++)
				{
					if(x > px1[j] && x < px2[j])
					{
						temp = py1[j] + (double)(py2[j]-py1[j]) / (px2[j]-px1[j]) * (double)(x-px1[j]);
						/*printf("%.3lf\n", temp);*/
						if(temp > max && temp < y)
						{
							max = temp;
							best = j;
						}
					}
				}
				if(max < 0.0)
				{
					printf("%d\n", x);
					break;
				}
				if(py1[best] > py2[best])
				{
					x = px2[best];
					y = py2[best];
				}
				else
				{
					x = px1[best];
					y = py2[best];
				}
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
