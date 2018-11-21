#include <stdio.h>
#include <string.h>
#include <math.h>

int wayx[128], wayy[128];
char str[1001], buf[1001];
double SQ2 = sqrt(2.0) / 2.0;

int main()
{
	int cas, step;
	char *ptr;
	double x, y, xdis, ydis, unit;
	cas = 0;
	wayx['N'] = wayx['S'] = 0;
	wayx['E'] = 1;
	wayx['W'] = -1;
	wayy['E'] = wayy['W'] = 0;
	wayy['N'] = 1;
	wayy['S'] = -1;
	while(gets(str))
	{
		if(!strcmp(str, "END"))
		{
			break;
		}
		ptr = strtok(str, ",.");
		x = y = 0;
		do
		{
			sscanf(ptr, "%d%s", &step, buf);
			xdis = ydis = 0;
			if(buf[1])
			{
				unit = SQ2;
				xdis = wayx[buf[0]] + wayx[buf[1]];
				ydis = wayy[buf[0]] + wayy[buf[1]];
			}
			else
			{
				unit = 1;
				xdis = wayx[buf[0]];
				ydis = wayy[buf[0]];
			}
			x += xdis * unit * step;
			y += ydis * unit * step;
		}while(ptr=strtok(NULL, ",."));
		printf("Map #%d\n", ++cas);
		printf("The treasure is located at (%.3lf,%.3lf).\n", x+1e-8, y+1e-8);
		printf("The distance to the treasure is %.3lf.\n\n", sqrt(x*x+y*y)+1e-8);
	}
	return 0;
}
