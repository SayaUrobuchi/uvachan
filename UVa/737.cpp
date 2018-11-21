#include <stdio.h>

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, flag, nowx, nowy, nowz, endx, endy, endz, length, newx, newy, newz, newl;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		flag = 1;
		scanf("%d%d%d%d", &nowx, &nowy, &nowz, &length);
		endx = nowx + length;
		endy = nowy + length;
		endz = nowz + length;
		while(--n)
		{
			scanf("%d%d%d%d", &newx, &newy, &newz, &newl);
			if(flag)
			{
				nowx = max(newx, nowx);
				nowy = max(newy, nowy);
				nowz = max(newz, nowz);
				endx = min(newx+newl, endx);
				endy = min(newy+newl, endy);
				endz = min(newz+newl, endz);
				flag &= (endx > nowx && endy > nowy && endz > nowz);
			}
		}
		if(flag)
		{
			printf("%d\n", (endx-nowx)*(endy-nowy)*(endz-nowz));
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
