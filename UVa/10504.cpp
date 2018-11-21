#include <stdio.h>
#include <string.h>

int n;
int aryx[26][10000], aryy[26][10000], num[26];
char map[101][101];
char str[100];

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < n;
}

int main()
{
	int cas, m, i, j, x, y, tx, ty, fx, fy, ch, ans, xdif, ydif;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		memset(num, 0, sizeof(num));
		scanf("%d", &m);
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
			for(j=0; j<n; j++)
			{
				ch = map[i][j] - 65;
				aryx[ch][num[ch]] = i;
				aryy[ch][num[ch]++] = j;
			}
		}
		while(m--)
		{
			scanf("%s", str);
			ch = str[0] - 65;
			for(i=0, ans=0; i<num[ch]; i++)
			{
				x = aryx[ch][i];
				y = aryy[ch][i];
				for(j=i+1; j<num[ch]; j++)
				{
					tx = aryx[ch][j];
					ty = aryy[ch][j];
					if(tx >= x && ty > y)
					{
						xdif = tx - x;
						ydif = ty - y;
						fx = tx + ydif;
						fy = ty - xdif;
						if(valid(fx, fy) && map[fx][fy] == ch + 65)
						{
							fx = x + ydif;
							fy = y - xdif;
							ans += (valid(fx, fy) && map[fx][fy] == ch + 65);
						}
					}
				}
			}
			printf("%c %d\n", ch+65, ans);
		}
	}
	return 0;
}
