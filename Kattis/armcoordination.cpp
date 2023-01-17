#include <iostream>
using namespace std;

const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, -1, 1};

int main()
{
	int x, y, r, i, tx, ty;
	scanf("%d%d%d", &x, &y, &r);
	for (i=0; i<4; i++)
	{
		tx = x + r * dx[i];
		ty = y + r * dy[i];
		printf("%d %d\n", tx, ty);
	}
	return 0;
}
