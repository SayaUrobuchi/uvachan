#include <stdio.h>

int px1[101], px2[101], py1[101], py2[101];

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

int side(int p, int q, int r, int s)
{
	return p*s - q*r;
}

int intersect(int i, int j)
{
	long long temp, temp2;
	temp = side(px1[i]-px2[i], py1[i]-py2[i], px1[j]-px2[i], py1[j]-py2[i]);
	temp2 = side(px1[i]-px2[i], py1[i]-py2[i], px2[j]-px2[i], py2[j]-py2[i]);
	if(temp * temp2 > 0)
	{
		return 0;
	}
	if(!temp && !temp2)
	{
		return min(px1[i], px2[i]) <= max(px1[j], px2[j]) && min(px1[j], px2[j]) <= max(px1[i], px2[i]) && min(py1[i], py2[i]) <= max(py1[j], py2[j]) && min(py1[j], py2[j]) <= max(py1[i], py2[i]);
	}
	temp = side(px1[j]-px2[j], py1[j]-py2[j], px1[i]-px2[j], py1[i]-py2[j]);
	temp2 = side(px1[j]-px2[j], py1[j]-py2[j], px2[i]-px2[j], py2[i]-py2[j]);
	return temp * temp2 <= 0;
}

int main()
{
	int count, n, c, i, j;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d%d", &px1[i], &py1[i], &px2[i], &py2[i]);
		}
		for(i=0, c=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(i != j)
				{
					if(intersect(i, j))
					{
						break;
					}
				}
			}
			c += (j == n);
		}
		printf("%d\n", c);
	}
	return 0;
}
