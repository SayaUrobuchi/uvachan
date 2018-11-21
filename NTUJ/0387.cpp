#include <stdio.h>

int ptr[100], hashx[3000], hashy[3000], map[60][60];

int min(int p, int q)
{
	return p<q ? p : q;
}

int ab(int p)
{
	return p<0 ? -p : p;
}

int main()
{
	int count, i, j, c, h, l, x, y, res;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &h, &l);
		for(i=0, c=0; i<h; i++)
		{
			for(j=0; j<l; j++)
			{
				scanf("%d", &map[i][j]);
				if(map[i][j] != -1)
				{
					hashx[map[i][j]] = i;
					hashy[map[i][j]] = j;
					c++;
				}
			}
			ptr[i] = 0;
		}
		for(i=1, res=0; i<=c; i++)
		{
			x = hashx[i];
			y = hashy[i];
			res += x * 20 + min(ab(y-ptr[x]), l-ab(y-ptr[x])) * 5;
			ptr[x] = y;
		}
		printf("%d\n", res);
	}
	return 0;
}
