/*
	ID: sa072682
	LANG: C
	TASK: ratios
*/
#include <stdio.h>

int qx[1000000], qy[1000000], qz[1000000], ary[3][3];
char chk[100][100][100];

int main()
{
	int i, j, x, y, z, tx, ty, tz, p, q, r;
	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);
	scanf("%d%d%d", &tx, &ty, &tz);
	for(i=0; i<3; i++)
	{
		scanf("%d%d%d", &ary[i][0], &ary[i][1], &ary[i][2]);
	}
	qx[0] = 1;
	qy[0] = 0;
	qz[0] = 0;
	qx[1] = 0;
	qy[1] = 1;
	qz[1] = 0;
	qx[2] = 0;
	qy[2] = 0;
	qz[2] = 1;
	for(i=0, j=3; i<j; i++)
	{
		x = qx[i];
		y = qy[i];
		z = qz[i];
		p = x * ary[0][0] + y * ary[1][0] + z * ary[2][0];
		q = x * ary[0][1] + y * ary[1][1] + z * ary[2][1];
		r = x * ary[0][2] + y * ary[1][2] + z * ary[2][2];
		if(((!tx && !p) || (tx && !(p % tx))) && ((!ty && !q) || (ty && !(q % ty))) && ((!tz && !r) || (tz && !(r % tz))) && ((!tx || !ty) || (tx && ty && p / tx == q / ty)) && ((!ty || !tz) || (ty && tz && q / ty == r / tz)))
		{
			if(tx)
			{
				printf("%d %d %d %d\n", x, y, z, p/tx);
			}
			else if(ty)
			{
				printf("%d %d %d %d\n", x, y, z, q/ty);
			}
			else if(tz)
			{
				printf("%d %d %d %d\n", x, y, z, r/tz);
			}
			break;
		}
		if(x + 1 < 100 && !chk[x+1][y][z])
		{
			chk[x+1][y][z] = 1;
			qx[j] = x + 1;
			qy[j] = y;
			qz[j++] = z;
		}
		if(y + 1 < 100 && !chk[x][y+1][z])
		{
			chk[x][y+1][z] = 1;
			qx[j] = x;
			qy[j] = y + 1;
			qz[j++] = z;
		}
		if(z + 1 < 100 && !chk[x][y][z+1])
		{
			chk[x][y][z+1] = 1;
			qx[j] = x;
			qy[j] = y;
			qz[j++] = z + 1;
		}
	}
	if(i == j)
	{
		printf("NONE\n");
	}
	scanf(" ");
	return 0;
}
