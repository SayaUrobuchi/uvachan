#include <stdio.h>

int dx[]={1, 0, -1, 0}, dy[]={0, -1, 0, 1};

int main()
{
	int n, m, i, j, x, y, cnt;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(i=0, j=1, x=y=n/2+1, cnt=1; cnt<m; )
		{
			x += dx[i] * j;
			y += dy[i] * j;
			cnt += j;
			if(cnt >= m)
			{
				break;
			}
			i = (i+1) % 4;
			x += dx[i] * j;
			y += dy[i] * j;
			cnt += j;
			if(cnt >= m)
			{
				break;
			}
			i = (i+1) % 4;
			j++;
		}
		x -= dx[i] * (cnt-m);
		y -= dy[i] * (cnt-m);
		printf("Line = %d, column = %d.\n", x, y);
	}
	return 0;
}
