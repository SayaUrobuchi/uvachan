#include <stdio.h>
#include <string.h>

int n, m;
int ary[55][75];
int num[55];
int table[55];
int used[75];
int sitted[55];
int seat[75][55];
int member[75];

int fill(int);

int sit(int now)
{
	int i, temp;
	if(num[now] == table[now])
	{
		for(i=0; i<num[now]; i++)
		{
			if(!used[temp=ary[now][i]])
			{
				if(fill(temp))
				{
					seat[temp][now] = 0;
					ary[now][i] = ary[now][--num[now]];
					return 1;
				}
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

int fill(int now)
{
	int i;
	used[now] = 1;
	for(i=0; i<m; i++)
	{
		if(!seat[now][i] && !sitted[i])
		{
			sitted[i] = 1;
			if(sit(i))
			{
				seat[now][i] = 1;
				ary[i][num[i]++] = now;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i, j, c;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &member[i]);
		}
		for(i=0; i<m; i++)
		{
			scanf("%d", &table[i]);
		}
		memset(seat, 0, sizeof(seat));
		memset(num, 0, sizeof(num));
		for(i=0; i<n; i++)
		{
			for(j=0; j<member[i]; j++)
			{
				memset(used, 0, sizeof(used));
				memset(sitted, 0, sizeof(sitted));
				if(!fill(i))
				{
					break;
				}
			}
			if(j < member[i])
			{
				break;
			}
		}
		if(i == n)
		{
			printf("1\n");
			for(i=0; i<n; i++)
			{
				for(j=0, c=0; j<m; j++)
				{
					if(seat[i][j])
					{
						if(c)
						{
							printf(" ");
						}
						c = 1;
						printf("%d", j+1);
					}
				}
				printf("\n");
			}
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
