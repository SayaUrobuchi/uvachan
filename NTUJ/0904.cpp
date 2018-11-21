#include <stdio.h>
#include <string.h>

int n, gg;
int used[250][250];
char map[250][250];

void check(int p, int q)
{
	if(p < 0 || p >= n-1 || q < 0 || map[p][q] == 0 || map[p][q+1] == 0)
	{
		return;
	}
	if(map[p][q] == ' ')
	{
		return;
	}
	if((p+q) % 2 == 0)
	{
		if(map[p][q] == '^' && map[p+1][q] == 'v' && map[p][q+1] == '^' && map[p+1][q+1] == 'v')
		{
			if(used[p][q]&&0)
			{
				gg = 1;
				return;
			}
			map[p][q] = '<';
			map[p][q+1] = '>';
			map[p+1][q] = '<';
			map[p+1][q+1] = '>';
			used[p][q] = 1;
			check(p-1, q);
			check(p+1, q);
		}
	}
	else
	{
		if(map[p][q] == '<' && map[p+1][q] == '<' && map[p][q+1] == '>' && map[p+1][q+1] == '>')
		{
			if(used[p][q]&&0)
			{
				gg = 1;
				return;
			}
			map[p][q] = '^';
			map[p][q+1] = '^';
			map[p+1][q] = 'v';
			map[p+1][q+1] = 'v';
			used[p][q] = 1;
			check(p, q+1);
			check(p, q-1);
		}
	}
}

int main()
{
	int count, i, j;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		gets(map[0]);
		memset(map, 0, sizeof(map));
		for(i=0; i<n; i++)
		{
			gets(map[i]);
			for(j=strlen(map[i])-1; j>=0; j--)
			{
				if(map[i][j] == ' ')
				{
					map[i][j] = 0;
				}
				else
				{
					break;
				}
			}
		}
		memset(used, 0, sizeof(used));
		gg = 0;
		for(i=0; i<n&&!gg; i++)
		{
			for(j=0; map[i][j]; j++)
			{
				check(i, j);
				if(gg)
				{
					break;
				}
			}
		}
		if(gg)
		{
			printf("Run away little girl. Run Away!\n");
		}
		else
		{
			for(i=0; i<n; i++)
			{
				printf("%s\n", map[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
