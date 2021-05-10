#include <iostream>

int ucnt;
int used[1024], pos[1024];

int main()
{
	int count, m, i, a, b, c, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &m);
		++ucnt;
		a = b = 1;
		for (i=2; ; i++)
		{
			c = (a + b) % m;
			a = b;
			b = c;
			if (used[c] == ucnt)
			{
				ans = pos[c];
				break;
			}
			used[c] = ucnt;
			pos[c] = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}