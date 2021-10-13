#include <iostream>
using namespace std;

int ary[1048576];

int main()
{
	int n, i, t, u, head, tail;
	while (scanf("%d", &n) == 1)
	{
		head = tail = 1e5+8;
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &t, &u);
			if (t == 1)
			{
				ary[--head] = u;
			}
			else if (t == 2)
			{
				ary[tail++] = u;
			}
			else
			{
				printf("%d\n", ary[head+u-1]);
			}
		}
	}
	return 0;
}
