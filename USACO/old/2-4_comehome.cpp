/*
	ID: sa072682
	LANG: C
	TASK: comehome
*/
#include <stdio.h>

int map[52][52], dis[52];
char chk[52], used[52];

int trans(char* s)
{
	if(*s > 90)
	{
		return *s - 71;
	}
	return *s - 65;
}

int main()
{
	int n, m, i, j, min, temp;
	char s[2], s2[2];
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%s%s%d", s, s2, &m);
		if(!map[trans(s)][trans(s2)] || map[trans(s)][trans(s2)] > m)
		{
			map[trans(s)][trans(s2)] = map[trans(s2)][trans(s)] = m;
		}
		chk[trans(s)] = chk[trans(s2)] = 1;
	}
	for(i=0; i<52; i++)
	{
		dis[i] = map[25][i];
	}
	for(i=0; i<52; i++)
	{
		for(j=0, min=2147483647; j<52; j++)
		{
			if(j != 25 && chk[j] && !used[j] && (dis[j] < min && dis[j]))
			{
				min = dis[j];
				temp = j;
			}
		}
		if(min == 2147483647)
		{
			break;
		}
		used[temp] = 1;
		for(j=0; j<52; j++)
		{
			if(j != 25 && chk[j] && !used[j] && map[temp][j] && (dis[temp] + map[temp][j] < dis[j] || !dis[j]))
			{
				dis[j] = dis[temp] + map[temp][j];
			}
		}
	}
	for(i=0, min=2147483647; i<25; i++)
	{
		if(chk[i] && dis[i] < min)
		{
			min = dis[i];
			temp = i;
		}
	}
	printf("%c %d\n", temp+65, min);
	scanf(" ");
	return 0;
}
