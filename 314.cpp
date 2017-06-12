#include <stdio.h>
#include <string.h>

char queue[10000][4], map[51][51], check[50][50][4], n, m;
int step[10000];

char dir(char* str)
{
	if(str[0] == 'n') return 0;
	if(str[0] == 'e') return 1;
	if(str[0] == 's') return 2;
	return 3;
}

char checkrange(char x, char y)
{
	if(x > 0 && x < n && y > 0 && y < m) return 1;
	return 0;
}

char turnleft(char face)
{
	if(face) return face - 1;
	else return 3;
}

char turnright(char face)
{
	if(face == 3) return 0;
	else return face + 1;
}

int main()
{
	int i, j, in;
	char k, y, x, z, buf[10], tmp, targety, targetx, walk[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m) break;
		memset(map, 1, n*50);
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &in);
				if(in)
				{
					map[i][j] = 0;
					map[i+1][j] = 0;
					map[i][j+1] = 0;
					map[i+1][j+1] = 0;
				}
			}
		}
		scanf("%d%d%d%d%s", &x, &y, &targetx, &targety, buf);
		if(x == targetx && y == targety)
		{
			printf("0\n");
			continue;
		}
		if(checkrange(targetx, targety) && map[targetx][targety])
		{
			memset(check, 1, n*200);
			z = dir(buf);
			queue[0][0] = x;
			queue[0][1] = y;
			queue[0][2] = z;
			step[0] = 0;
			check[x][y][z] = 0;
			for(i=0, j=1; i<j; i++)
			{
				x = queue[i][0];
				y = queue[i][1];
				z = queue[i][2];
				tmp = turnleft(z);
				if(check[x][y][tmp])
				{
					check[x][y][tmp] = 0;
					queue[j][0] = x;
					queue[j][1] = y;
					queue[j][2] = tmp;
					step[j++] = step[i] + 1;
				}
				tmp = turnright(z);
				if(check[x][y][tmp])
				{
					check[x][y][tmp] = 0;
					queue[j][0] = x;
					queue[j][1] = y;
					queue[j][2] = tmp;
					step[j++] = step[i] + 1;
				}
				for(k=0; k<3; k++)
				{
					x += walk[z][0];
					y += walk[z][1];
					if(checkrange(x, y) && map[x][y])
					{
            if(x == targetx && y == targety) break;
						if(check[x][y][z])
						{
							check[x][y][z] = 0;
							queue[j][0] = x;
							queue[j][1] = y;
							queue[j][2] = z;
							step[j++] = step[i] + 1;
						}
					}
					else break;
				}
				if(x == targetx && y == targety) break;
			}
			if(i == j) printf("-1\n");
			else printf("%d\n", step[i] + 1);
		}
		else printf("-1\n");
	}
	return 0;
}
