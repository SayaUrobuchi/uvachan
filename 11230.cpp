#include <stdio.h>
#include <string.h>

char map[100][101], board[100][101];

int main()
{
	int n, m, i, j, k, l, p, q, r, c, ans;
	while(scanf("%d%d%d%d", &n, &m, &r, &c) == 4)
	{
		if(!(n + m + r + c))
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				board[i][j] = 48;
			}
			board[i][j] = 0;
		}
		for(i=r, n++, m++, ans=0; i<n; i++)
		{
			for(j=c; j<m; j++)
			{
				k = i - r;
				l = j - c;
				if(map[k][l] != board[k][l])
				{
					for(p=k; p<i; p++)
					{
						for(q=l; q<j; q++)
						{
							board[p][q] = (board[p][q] == 49 ? 48 : 49);
						}
					}
					ans++;
				}
			}
			for(j=m-c, k=i-r, l=m-1; j<l; j++)
			{
				if(board[k][j] != map[k][j])
				{
					ans = -1;
					break;
				}
			}
			if(j < l)
			{
				break;
			}
		}
		for(i=n-r, n--; i<n; i++)
		{
			if(strcmp(map[i], board[i]))
			{
				ans = -1;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
