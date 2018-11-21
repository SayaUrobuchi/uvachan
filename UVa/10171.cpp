#include <stdio.h>
#include <string.h>

int ymap[128][128], omap[128][128];
char queue[128];
char buf[2008];

int main()
{
	int n, i, j, k, temp, final, qnum;
	char *ptr, *p2;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(ymap, 1, sizeof(ymap));
		memset(omap, 1, sizeof(omap));
		for(i='A'; i<='Z'; i++)
		{
			ymap[i][i] = omap[i][i] = 0;
		}
		gets(buf);
		while(n--)
		{
			gets(buf);
			for(ptr=buf, p2=buf; p2-buf<4; ptr++)
			{
				if(*ptr != ' ')
				{
					*(p2++) = *ptr;
				}
			}
			sscanf(ptr, "%d", &temp);
			if(buf[0] == 'Y')
			{
				if(buf[1] == 'B' && ymap[buf[3]][buf[2]] > temp)
				{
					ymap[buf[3]][buf[2]] = temp;
				}
				if(ymap[buf[2]][buf[3]] > temp)
				{
					ymap[buf[2]][buf[3]] = temp;
				}
			}
			else
			{
				if(buf[1] == 'B' && omap[buf[3]][buf[2]] > temp)
				{
					omap[buf[3]][buf[2]] = temp;
				}
				if(omap[buf[2]][buf[3]] > temp)
				{
					omap[buf[2]][buf[3]] = temp;
				}
			}
		}
		gets(buf);
		for(ptr=buf, p2=buf; p2-buf<2; ptr++)
		{
			if(*ptr != ' ')
			{
				*(p2++) = *ptr;
			}
		}
		for(k='A'; k<='Z'; k++)
		{
			for(i='A'; i<='Z'; i++)
			{
				for(j='A'; j<='Z'; j++)
				{
					if(ymap[i][k] + ymap[k][j] < ymap[i][j])
					{
						ymap[i][j] = ymap[i][k] + ymap[k][j];
					}
					if(omap[i][k] + omap[k][j] < omap[i][j])
					{
						omap[i][j] = omap[i][k] + omap[k][j];
					}
				}
			}
		}
		for(i='A', qnum=0, final=100000; i<='Z'; i++)
		{
			if(ymap[buf[0]][i] + omap[buf[1]][i] < final)
			{
				qnum = 1;
				final = ymap[buf[0]][i] + omap[buf[1]][i];
				queue[0] = i;
			}
			else if(ymap[buf[0]][i] + omap[buf[1]][i] == final)
			{
				queue[qnum++] = i;
			}
		}
		if(qnum)
		{
			printf("%d", final);
			for(i=0; i<qnum; i++)
			{
				printf(" %c", queue[i]);
			}
			printf("\n");
		}
		else
		{
			printf("You will never meet.\n");
		}
	}
	return 0;
}
