#include <stdio.h>

short set[10001];

int gethead(int now)
{
	if(set[now] < 1)
	{
		return now;
	}
	return set[now] = gethead(set[now]);
}

int main()
{
	int n, i, c, x, y, xhead, yhead;
	while(scanf("%d", &n) == 1)
	{
		for(i=1, n++; i<n; i++)
		{
			set[i] = 0;
		}
		while(scanf("%d%d%d", &c, &x, &y) == 3)
		{
			if(!c && !x && !y)
			{
				break;
			}
			xhead = gethead(x+1);
			yhead = gethead(y+1);
			if(c == 1)
			{
				if(xhead != yhead)
				{
					if(-set[xhead] == yhead)
					{
						printf("-1\n");
					}
					else
					{
						if(set[yhead])
						{
							set[-set[xhead]] = -set[yhead];
							set[-set[yhead]] = -xhead;
							set[xhead] = set[yhead];
							set[yhead] = xhead;
						}
						else
						{
							set[yhead] = xhead;
						}
					}
				}
			}
			else if(c == 2)
			{
				if(-set[xhead] != yhead)
				{
					if(xhead == yhead)
					{
						printf("-1\n");
					}
					else
					{
						set[-set[xhead]] = yhead;
						set[-set[yhead]] = xhead;
						set[yhead] = -xhead;
						set[xhead] = -yhead;
					}
				}
			}
			else if(c == 3)
			{
				if(xhead == yhead)
				{
					printf("1\n");
				}
				else
				{
					printf("0\n");
				}
			}
			else
			{
				if(-set[xhead] == yhead)
				{
					printf("1\n");
				}
				else
				{
					printf("0\n");
				}
			}
		}
	}
	return 0;
}
