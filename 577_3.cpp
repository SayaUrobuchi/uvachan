#include <stdio.h>
#include <string.h>

int queuex[10005], queuey[10005];
char buf[1005];

struct data
{
	int id;
	int maximize;
	int origx1, origx2, origy1, origy2;
	int currx1, currx2, curry1, curry2;
};

struct data window[10005];

int main()
{
	int n, m, o, i, x, y, cx, cy, now, xshift, yshift, clickarea, releasearea, cr;
	struct data temp;
	m = n = o = 0;
	clickarea = releasearea = 0;
	cr = 0;
	while(scanf("%s", buf) == 1)
	{
		if(!strcmp(buf, "ZZ"))
		{
			break;
		}
		if(!strcmp(buf, "RE"))
		{
			for(i=0; i<n; i++)
			{
				printf("Window %d at %d, %d, %d, %d\n", window[i].id, window[i].currx1, window[i].curry1, window[i].currx2, window[i].curry2);
			}
		}
		else if(!strcmp(buf, "DN"))
		{
			cr = 1;
			scanf("%d%d", &x, &y);
			for(i=n-1; i>=0; i--)
			{
				if(x >= window[i].currx1 && x <= window[i].currx2 && y >= window[i].curry1 && y <= window[i].curry2)
				{
					printf("Selected window %d\n", window[i].id);
					if(y < window[i].curry1 + 25 && x < window[i].currx1 + 25)
					{
						clickarea = 1;
					}
					else if(y < window[i].curry1 + 25 && x > window[i].currx2 - 25)
					{
						clickarea = 2;
					}
					else if(y < window[i].curry1 + 25)
					{
						clickarea = 3;
					}
					else
					{
						clickarea = 4;
					}
					cx = x;
					cy = y;
					break;
				}
			}
			if(i >= 0)
			{
				temp = window[i];
				for(i++; i<n; i++)
				{
					window[i-1] = window[i];
				}
				window[i-1] = temp;
				now = n - 1;
			}
		}
		else if(!strcmp(buf, "UP"))
		{
			scanf("%d%d", &x, &y);
			releasearea = 0;
			if(x >= window[n-1].currx1 && x <= window[n-1].currx2 && y >= window[n-1].curry1 && y <= window[n-1].curry2)
			{
				if(y < window[n-1].curry1 + 25 && x < window[n-1].currx1 + 25)
				{
					releasearea = 1;
				}
				else if(y < window[n-1].curry1 + 25 && x > window[n-1].currx2 - 25)
				{
					releasearea = 2;
				}
				else if(y < window[n-1].curry1 + 25)
				{
					releasearea = 3;
				}
				else
				{
					releasearea = 4;
				}
			}
			if(releasearea == clickarea && cr)
			{
				if(clickarea == 1)
				{
					printf("Closed window %d\n", window[n-1].id);
					n--;
				}
				else if(clickarea == 2)
				{
					if(window[n-1].maximize)
					{
						window[n-1].maximize = 0;
						window[n-1].currx1 = window[n-1].origx1;
						window[n-1].currx2 = window[n-1].origx2;
						window[n-1].curry1 = window[n-1].origy1;
						window[n-1].curry2 = window[n-1].origy2;
					}
					else
					{
						window[n-1].maximize = 1;
						window[n-1].currx1 = 0;
						window[n-1].currx2 = 1023;
						window[n-1].curry1 = 0;
						window[n-1].curry2 = 1023;
					}
					printf("Resized window %d to %d, %d, %d, %d\n", window[n-1].id, window[n-1].currx1, window[n-1].curry1, window[n-1].currx2, window[n-1].curry2);
				}
			}
			if(clickarea == 3 && !window[n-1].maximize)
			{
				xshift = cx - x;
				yshift = cy - y;
				window[n-1].origx1 = window[n-1].currx1 -= xshift;
				window[n-1].origx2 = window[n-1].currx2 -= xshift;
				window[n-1].origy1 = window[n-1].curry1 -= yshift;
				window[n-1].origy2 = window[n-1].curry2 -= yshift;
				printf("Moved window %d to %d, %d, %d, %d\n", window[n-1].id, window[n-1].currx1, window[n-1].curry1, window[n-1].currx2, window[n-1].curry2);
			}
			clickarea = 0;
			cr = 0;
		}
		else if(!strcmp(buf, "AT"))
		{
			scanf("%d%d", &x, &y);
			if(clickarea == 3 && !window[n-1].maximize)
			{
				xshift = cx - x;
				yshift = cy - y;
				window[n-1].origx1 = window[n-1].currx1 -= xshift;
				window[n-1].origx2 = window[n-1].currx2 -= xshift;
				window[n-1].origy1 = window[n-1].curry1 -= yshift;
				window[n-1].origy2 = window[n-1].curry2 -= yshift;
				printf("Moved window %d to %d, %d, %d, %d\n", window[n-1].id, window[n-1].currx1, window[n-1].curry1, window[n-1].currx2, window[n-1].curry2);
			}
			cx = x;
			cy = y;
		}
		else
		{
			cr = 0;
			scanf("%d%d%d%d", &window[n].origx1, &window[n].origy1, &window[n].origx2, &window[n].origy2);
			printf("Created window %d at %d, %d, %d, %d\n", m, window[n].origx1, window[n].origy1, window[n].origx2, window[n].origy2);
			window[n].id = m;
			window[n].currx1 = window[n].origx1;
			window[n].curry1 = window[n].origy1;
			window[n].currx2 = window[n].origx2;
			window[n].curry2 = window[n].origy2;
			window[n].maximize = 0;
			m++;
			n++;
		}
	}
	return 0;
}
