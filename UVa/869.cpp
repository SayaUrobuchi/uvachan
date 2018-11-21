#include <stdio.h>
#include <string.h>

char map1[30][30], map2[30][30], b1[30], b2[30];

int main()
{
	int count, m, i, j, k;
	scanf("%d", &count);
	while(count--)
	{
		memset(map1, 0, sizeof(map1));
		memset(map2, 0, sizeof(map2));
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s%s", b1, b2);
			map1[b1[0]-65][b2[0]-65] = map1[b2[0]-65][b1[0]-65] = 1;
		}
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s%s", b1, b2);
			map2[b1[0]-65][b2[0]-65] = map2[b2[0]-65][b1[0]-65] = 1;
		}
		for(k=0; k<26; k++)
		{
			for(i=0; i<26; i++)
			{
				for(j=0; j<26; j++)
				{
					map1[i][j] |= (map1[i][k] && map1[k][j]);
				}
			}
		}
		for(k=0; k<26; k++)
		{
			for(i=0; i<26; i++)
			{
				for(j=0; j<26; j++)
				{
					map2[i][j] |= (map2[i][k] && map2[k][j]);
				}
			}
		}
		if(memcmp(map1, map2, sizeof(map1)))
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
