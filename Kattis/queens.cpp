#include <iostream>

int ucnt;
int row[16384], col[16384], add[32768], sub[32768];

int main()
{
	int n, i, x, y;
	bool gg;
	while (scanf("%d", &n) == 1)
	{
		++ucnt;
		for (i=0, gg=false; i<n; i++)
		{
			scanf("%d%d", &x, &y);
			if (row[x] == ucnt || col[y] == ucnt || add[x+y] == ucnt || sub[x-y+n] == ucnt)
			{
				gg = true;
			}
			else
			{
				row[x] = col[y] = add[x+y] = sub[x-y+n] = ucnt;
			}
		}
		puts(gg ? "INCORRECT" : "CORRECT");
	}
	return 0;
}
