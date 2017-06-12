#include <stdio.h>
#include <string.h>

int n, m, o;
int row[201], column[201];
int aryx[401], aryy[401];
int conn[401][401], num[401];
int used[401], chk[201];
int tused[401], tchk[201];

int dfs(int now)
{
	int i;
	for(i=0; i<num[now]; i++)
	{
		if(!used[conn[now][i]])
		{
			if(chk[conn[now][i]/2])
			{
				return 1;
			}
			chk[conn[now][i]/2] = 1;
			used[conn[now][i]] = 1;
			if(dfs(conn[now][i]))
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int count, i, j, p, q, r, s;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		memset(num, 0, sizeof(num));
		for(i=0, p=0; i<o; i++, p+=2)
		{
			q = p + 1;
			scanf("%d%d%d%d", &aryx[p], &aryy[q], &aryx[q], &aryy[p]);
			if(aryx[p] > aryx[q])
			{
				row[i] = 1;
			}
			else if(aryx[p] == aryx[q])
			{
				row[i] = 0;
			}
			else
			{
				row[i] = 2;
			}
			if(aryy[p] > aryy[q])
			{
				column[i] = 1;
			}
			else if(aryy[p] == aryy[q])
			{
				column[i] = 0;
			}
			else
			{
				column[i] = 2;
			}
			for(j=0, r=0; j<i; j++, r+=2)
			{
				s = r + 1;
				if((aryx[p] == aryx[r] && column[i] + column[j] == 3) || (aryy[p] == aryy[r] && row[i] + row[j] == 3))
				{
					conn[p][num[p]++] = s;
					conn[r][num[r]++] = q;
				}
				if((aryx[p] == aryx[s] && column[i] + column[j] == 3) || (aryy[p] == aryy[s] && row[i] + row[j] == 3))
				{
					conn[p][num[p]++] = r;
					conn[s][num[s]++] = q;
				}
				if((aryx[q] == aryx[r] && column[i] + column[j] == 3) || (aryy[q] == aryy[r] && row[i] + row[j] == 3))
				{
					conn[q][num[q]++] = s;
					conn[r][num[r]++] = p;
				}
				if((aryx[q] == aryx[s] && column[i] + column[j] == 3) || (aryy[q] == aryy[s] && row[i] + row[j] == 3))
				{
					conn[q][num[q]++] = r;
					conn[s][num[s]++] = p;
				}
			}
		}
		memset(used, 0, sizeof(used));
		memset(chk, 0, sizeof(chk));
		for(i=0, p=0; i<o; i++, p+=2)
		{
			q = p + 1;
			if(!chk[i])
			{
				used[p] = 1;
				chk[i] = 1;
				memcpy(tused, used, sizeof(used));
				memcpy(tchk, chk, sizeof(chk));
				if(dfs(p))
				{
					memcpy(used, tused, sizeof(used));
					memcpy(chk, tchk, sizeof(chk));
					used[p] = 0;
					used[q] = 1;
					if(dfs(q))
					{
						break;
					}
				}
			}
		}
		if(i == o)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
