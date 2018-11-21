#include <stdio.h>
#include <string.h>

int map[128][128];
char s[100000], res[100000];

int main()
{
	int n, m, i, j, k, l, f, c, r;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		memset(map, 0, sizeof(map));
		for(l=0, f=0; l<m; l++)
		{
			scanf("%s", s);
			if(f == 0)
			{
				map[s[0]][s[2]] = 1;
				for(k='A'; k<'A'+n; k++)
				{
					for(i='A'; i<'A'+n; i++)
					{
						if(map[i][k])
						{
							for(j='A'; j<'A'+n; j++)
							{
								map[i][j] |= (map[i][k] & map[k][j]);
							}
						}
					}
				}
				memset(res, 0, sizeof(res));
				for(i='A'; i<'A'+n; i++)
				{
					for(j='A', c=0; j<'A'+n; j++)
					{
						if(map[i][j] && map[j][i])
						{
							f = 2;
							r = l+1;
							break;
						}
						c += map[i][j];
					}
					if(f == 2)
					{
						break;
					}
					if(res[n-c-1])
					{
						break;
					}
					res[n-c-1] = i;
				}
				if(i == 'A'+n)
				{
					f = 1;
					r = l+1;
				}
			}
		}
		if(f == 2)
		{
			printf("Inconsistency found after %d relations.\n", r);
		}
		else if(f == 1)
		{
			printf("Sorted sequence determined after %d relations: %s.\n", r, res);
		}
		else
		{
			printf("Sorted sequence cannot be determined.\n");
		}
	}
	return 0;
}
