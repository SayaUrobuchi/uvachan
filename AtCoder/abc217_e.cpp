#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int m, i, t, cmd;
	while (scanf("%d", &m) == 1)
	{
		queue<int> qq;
		priority_queue<int, vector<int>, greater<int> > pq;
		for (i=0; i<m; i++)
		{
			scanf("%d", &cmd);
			if (cmd == 1)
			{
				scanf("%d", &t);
				qq.emplace(t);
			}
			else if (cmd == 2)
			{
				if (pq.size())
				{
					printf("%d\n", pq.top());
					pq.pop();
				}
				else
				{
					printf("%d\n", qq.front());
					qq.pop();
				}
			}
			else
			{
				while (qq.size())
				{
					pq.emplace(qq.front());
					qq.pop();
				}
			}
		}
	}
	return 0;
}

