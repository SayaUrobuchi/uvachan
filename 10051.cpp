#include <stdio.h>
#include <string.h>

int list[6];
int from[6];
int color[6];
int len[101];
int lastcolor[101][501];
char str[101][501][20];
char buf[6][101] = {"front", "back", "left", "right", "top", "bottom"};

char *getstr(int now)
{
	return buf[now];
}

void backtracing(int color, int len)
{
	if(!len)
	{
		return;
	}
	backtracing(lastcolor[color][len], len-1);
	printf("%s\n", str[color][len]);
}

int main()
{
	int cas, n, i, j, c1, c2, max, temp;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(len, 0, sizeof(len));
		for(i=0; i<n; i++)
		{
			for(j=0; j<6; )
			{
				scanf("%d%d", &c1, &c2);
				list[j] = len[c1] + 1;
				from[j] = c1;
				color[j++] = c2;
				list[j] = len[c2] + 1;
				from[j] = c2;
				color[j++] = c1;
			}
			for(j=0; j<6; j++)
			{
				if(len[color[j]] < list[j])
				{
					len[color[j]] = list[j];
					sprintf(str[color[j]][list[j]], "%d %s", i+1, getstr(j));
					lastcolor[color[j]][list[j]] = from[j];
				}
			}
		}
		for(i=1, max=0; i<=100; i++)
		{
			if(len[i] > max)
			{
				max = len[i];
				temp = i;
			}
		}
		if(cas)
		{
			printf("\n");
		}
		printf("Case #%d\n%d\n", ++cas, max);
		backtracing(temp, max);
	}
	return 0;
}
