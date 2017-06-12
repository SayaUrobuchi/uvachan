#include <stdio.h>

#define LEFT 0
#define RIGHT 1

int tx, ty, bx, by, shift;

void recursion(int x, int y, int direct, int depth, int limit)
{
	if(depth >= limit)
	{
		return;
	}
	if(direct == LEFT)
	{
		recursion(x>>1, y>>1, direct, depth+1, limit);
		/*printf("%d %d\n", x, y);*/
		printf("(%d,%d)(%d,0)\n", tx, ty, bx);
		printf("(%d,0)(%d,0)\n", bx, x);
		printf("(%d,0)(%d,%d)\n", x, x-(x>>1), y);
		printf("(%d,%d)(%d,%d)\n", x-(x>>1), y, x+(x>>1), y);
		tx = (x + (x>>1));
		ty = y;
		bx = x;
	}
	else
	{
		/*printf("%d %d\n", shift-x, y);*/
		printf("(%d,%d)(%d,0)\n", tx, ty, bx);
		printf("(%d,0)(%d,0)\n", bx, shift-x);
		printf("(%d,0)(%d,%d)\n", shift-x, shift-x-(x>>1), y);
		printf("(%d,%d)(%d,%d)\n", shift-x-(x>>1), y, shift-x+(x>>1), y);
		tx = (shift - x + (x>>1));
		ty = y;
		bx = shift - x;
		recursion(x>>1, y>>1, direct, depth+1, limit);
	}
}

int main()
{
	int count, p, q, sx, sy;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d", &p, &q, &sx, &sy);
		tx = sx;
		ty = sy;
		bx = 0;
		by = 0;
		shift = (sx << 1);
		recursion(sx, sy>>1, LEFT, 0, p);
		recursion(sx>>1, sy>>2, RIGHT, 1, q);
		printf("(%d,%d)(%d,0)\n", tx, ty, bx);
		printf("(%d,0)(%d,0)\n", bx, sx<<1);
		printf("(%d,0)(%d,%d)\n", sx<<1, sx, sy);
		printf("\n");
	}
	return 0;
}
