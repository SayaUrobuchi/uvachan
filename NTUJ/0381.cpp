#include <stdio.h>
#include <math.h>

int hash[128];
int dirx[8]={-1, 0, 1, 1, 1, 0, -1, -1}, diry[8]={-1, -1, -1, 0, 1, 1, 1, 0};

int main()
{
	int count, x, y, lastx, lasty;
	char cmd[1000005], *p;
	double res;
	hash['1'] = 0;
	hash['2'] = 1;
	hash['3'] = 2;
	hash['6'] = 3;
	hash['9'] = 4;
	hash['8'] = 5;
	hash['7'] = 6;
	hash['4'] = 7;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", cmd);
		lastx = 0;
		lasty = 0;
		for(p=cmd, res=0.0; *p!='5'; p++)
		{
			x = lastx + dirx[hash[*p]];
			y = lasty + diry[hash[*p]];
			res += lastx * y - lasty * x;
			lastx = x;
			lasty = y;
		}
		printf("%.1lf\n", fabs(res/2.0));
	}
	return 0;
}
