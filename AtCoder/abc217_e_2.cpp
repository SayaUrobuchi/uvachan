#include <iostream>
#include <algorithm>
using namespace std;

int ary[262144];

int main()
{
	int m, i, t, cmd, front, mid, tail;
	while (scanf("%d", &m) == 1)
	{
		for (i=0, front=0, mid=0, tail=0; i<m; i++)
		{
			scanf("%d", &cmd);
			if (cmd == 1)
			{
				scanf("%d", &t);
				ary[tail++] = t;
			}
			else if (cmd == 2)
			{
				printf("%d\n", ary[front++]);
			}
			else
			{
				mid = max(front, mid);
				sort(ary+mid, ary+tail);
				inplace_merge(ary+front, ary+mid, ary+tail);
				mid = tail;
			}
		}
	}
	return 0;
}

