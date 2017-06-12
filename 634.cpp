#include <stdio.h>

int x[1010], y[1010];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, i, px, py, l, u, r, d;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
		}
		x[n] = x[0];
		y[n] = y[0];
		scanf("%d%d", &px, &py);
		for(i=0, l=r=u=d=0; i<n; i++)
		{
			if(x[i] == x[i+1])
			{
				if(py >= min(y[i], y[i+1]) && py <= max(y[i], y[i+1]))
				{
					if(x[i] > px)
					{
						r++;
					}
					else
					{
						l++;
					}
				}
			}
			else
			{
				if(px >= min(x[i], x[i+1]) && px <= max(x[i], x[i+1]))
				{
					if(y[i] > py)
					{
						u++;
					}
					else
					{
						d++;
					}
				}
			}
		}
		if(l%2 && r%2 && u%2 && d%2)
		{
			printf("T\n");
		}
		else
		{
			printf("F\n");
		}
	}
	return 0;
}
