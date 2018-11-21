#include <stdio.h>
#include <string.h>

int loc[3000][3], point[100][2];

double getx(int i, int j)
{
	int newx, newconst;
	newx = loc[i][1] * loc[j][0] - loc[j][1] * loc[i][0];
	newconst = loc[i][1] * loc[j][2] - loc[j][1] * loc[i][2];
	return (double)(0 - newconst) / newx;
}

double gety(int i, int j)
{
	int newy, newconst;
	newy = loc[i][0] * loc[j][1] - loc[j][0] * loc[i][1];
	newconst = loc[i][0] * loc[j][2] - loc[j][0] * loc[i][2];
	return (double)(0 - newconst) / newy;
}

int main()
{
	int cas, n, p, i, j, k, px, py, ans;
	double x, y;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n) break;
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d", &loc[i][0], &loc[i][1], &loc[i][2]);
		}
		scanf("%d", &p);
		for(i=0; i<p; i++)
		{
			scanf("%d%d", &point[i][0], &point[i][1]);
		}
		ans = 0;
		for(i=0; i<n; i++)
		{
			for(j=0; j<i; j++)
			{
				x = getx(i, j);
				y = gety(i, j);
				printf("%.3f %.3f\n", x, y);
				for(k=0; k<p; k++)
				{
					px = point[k][0];
					py = point[k][1];
					if(px > x && py < y || px < x && py > y) ans++;
				}
			}
		}
		printf("Roadmap %d:\nNegative Builders Ltd. will build %d New Roads.\n", ++cas, ans);
	}
	return 0;
}
