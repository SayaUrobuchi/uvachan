#include <stdio.h>
#include <string.h>

#define N 11
#define M 11

int number[11][11] = {{0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0}, 
					  {0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0}, 
					  {0, 0,  0,  0,  1,  2,  3,  0,  0, 0, 0}, 
					  {0, 0,  0,  0,  4,  5,  6,  0,  0, 0, 0}, 
					  {0, 0,  7,  8,  9, 10, 11, 12, 13, 0, 0}, 
					  {0, 0, 14, 15, 16, 17, 18, 19, 20, 0, 0}, 
					  {0, 0, 21, 22, 23, 24, 25, 26, 27, 0, 0}, 
					  {0, 0,  0,  0, 28, 29, 30,  0,  0, 0, 0}, 
					  {0, 0,  0,  0, 31, 32, 33,  0,  0, 0, 0}, 
					  {0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0}, 
					  {0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0}};
int numx[34], numy[34];
int map[11][11];
int wayx[4] = {1, 0, 0, -1};
int wayy[4] = {0, 1, -1, 0};

int main()
{
	int count, i, j, k, bx, by, dx, dy, temp, ans;
	for(i=2; i<N-2; i++)
	{
		for(j=2; j<M-2; j++)
		{
			numx[number[i][j]] = i;
			numy[number[i][j]] = j;
		}
	}
	printf("HI Q OUTPUT\n");
	scanf("%d", &count);
	while(count--)
	{
		memset(map, 0, sizeof(map));
		while(scanf("%d", &temp) == 1)
		{
			if(!temp)
			{
				break;
			}
			map[numx[temp]][numy[temp]] = 1;
		}
		for(; ; )
		{
			for(i=N-3; i>=2; i--)
			{
				for(j=M-3; j>=2; j--)
				{
					if(number[i][j] && !map[i][j])
					{
						for(k=0; k<4; k++)
						{
							bx = i + wayx[k];
							by = j + wayy[k];
							dx = bx + wayx[k];
							dy = by + wayy[k];
							if(number[dx][dy] && map[bx][by] && map[dx][dy])
							{
								break;
							}
						}
						if(k < 4)
						{
							break;
						}
					}
				}
				if(j >= 2)
				{
					break;
				}
			}
			if(i >= 2)
			{
				map[i][j] = 1;
				map[bx][by] = map[dx][dy] = 0;
			}
			else
			{
				break;
			}
		}
		for(i=N-3, ans=0; i>=2; i--)
		{
			for(j=M-3; j>=2; j--)
			{
				if(map[i][j])
				{
					ans += number[i][j];
				}
			}
		}
		printf("%d\n", ans);
	}
	printf("END OF OUTPUT\n");
	return 0;
}
