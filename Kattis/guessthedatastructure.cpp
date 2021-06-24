#include <iostream>
#include <stack>
#include <queue>
using namespace std;

const int PUSH = 1;

int main()
{
	int n, i, cmd, t;
	bool a, b, c;
	while (scanf("%d", &n) == 1)
	{
		stack<int> stk;
		queue<int> que;
		priority_queue<int> pq;
		a = b = c = true;
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &cmd, &t);
			if (cmd == PUSH)
			{
				stk.push(t);
				que.push(t);
				pq.push(t);
			}
			else
			{
				if (stk.empty() || t != stk.top())
				{
					a = false;
				}
				else
				{
					stk.pop();
				}
				if (que.empty() || t != que.front())
				{
					b = false;
				}
				else
				{
					que.pop();
				}
				if (pq.empty() || t != pq.top())
				{
					c = false;
				}
				else
				{
					pq.pop();
				}
			}
		}
		if (!a && !b && !c)
		{
			puts("impossible");
		}
		else if ((int)a + (int)b + (int)c > 1)
		{
			puts("not sure");
		}
		else if (a)
		{
			puts("stack");
		}
		else if (b)
		{
			puts("queue");
		}
		else
		{
			puts("priority queue");
		}
	}
	return 0;
}
