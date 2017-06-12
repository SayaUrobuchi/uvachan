#include <stdio.h>
#include <string.h>

int ans;
int tbl[26];
int map[26][26], num[26];
int chk[26];
int alive[26];
char str[1000];

int dfs(int now)
{
	int i, j, temp, count;
	int ary[4];
	if(tbl[now] != -1)
	{
		return tbl[now];
	}
	memset(ary, 1, sizeof(ary));
	count = 0;
	/*printf("%c %d\n", now+65, num[now]);*/
	for(i=0; i<num[now]; i++)
	{
		if(!chk[map[now][i]])
		{
			/*printf("%c %c\n", now+65, map[now][i]+65);*/
			chk[map[now][i]] = 1;
			temp = dfs(map[now][i]);
			if(temp != -1)
			{
				count++;
				ary[3] = temp;
				for(j=3; j; j--)
				{
					if(ary[j-1] > ary[j])
					{
						temp = ary[j-1];
						ary[j-1] = ary[j];
						ary[j] = temp;
					}
					else
					{
						break;
					}
				}
			}
			chk[map[now][i]] = 0;
		}
	}
	if(count >= 3)
	{
		temp = ary[2] + 1;
		if(temp > ans)
		{
			ans = temp;
		}
		/*printf("%c %d\n", now+65, temp);
		printf("%d %d %d\n", ary[0], ary[1], ary[2]);*/
		return tbl[now] = temp;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int n, m, i, j;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(alive, 0, sizeof(alive));
		memset(num, 0, sizeof(num));
		scanf("%s", str);
		for(i=0; i<26; i++)
		{
			tbl[i] = -1;
		}
		for(i=0; str[i]; i++)
		{
			j = str[i] - 65;
			alive[j] = 1;
			tbl[j] = 0;
		}
		while(m--)
		{
			scanf("%s", str);
			i = str[0] - 65;
			j = str[1] - 65;
			alive[i] = alive[j] = 1;
			map[i][num[i]++] = j;
			map[j][num[j]++] = i;
		}
		for(i=0, ans=0; i<26; i++)
		{
			if(alive[i] && tbl[i] == -1)
			{
				memset(chk, 0, sizeof(chk));
				chk[i] = 1;
				if(dfs(i) == -1)
				{
					break;
				}
			}
			n -= alive[i];
		}
		if(i == 26 && !n)
		{
			printf("WAKE UP IN, %d, YEARS\n", ans);
		}
		else
		{
			printf("THIS BRAIN NEVER WAKES UP\n");
		}
	}
	return 0;
}
