#include <stdio.h>
#include <string.h>

char map[25][25], name[25][26], chk[25], num;

int getnum(char* str)
{
	int i;
	for(i=0; i<num; i++)
	{
		if(!strcmp(str, name[i]))
		{
			return i;
		}
	}
	strcpy(name[i], str);
	return num++;
}

int main()
{
	int cas, n, m, tmp, tmp2;
	char buf[26], buf2[26], i, j, k;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		memset(map, 0, sizeof(map));
		num = 0;
		while(m--)
		{
			scanf("%s%s", buf, buf2);
			tmp = getnum(buf);
			tmp2 = getnum(buf2);
			map[tmp][tmp2] = 1;
		}
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				if(map[i][k])
				{
					for(j=0; j<n; j++)
					{
						if(map[k][j])
						{
							map[i][j] = 1;
						}
					}
				}
			}
			chk[k] = 1;
		}
		if(cas)
		{
			printf("\n");
		}
		printf("Calling circles for data set %d:\n", ++cas);
		for(i=0; i<n; i++)
		{
			if(chk[i])
			{
				chk[i] = 0;
				printf("%s", name[i]);
				for(j=0; j<n; j++)
				{
					if(chk[j] && map[i][j] && map[j][i])
					{
						chk[j] = 0;
						printf(", %s", name[j]);
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}
