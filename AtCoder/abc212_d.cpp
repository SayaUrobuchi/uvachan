#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int m, i, cmd;
	long long t, fix;
	while (scanf("%d", &m) == 1)
	{
		priority_queue<long long, vector<long long>, greater<long long> > pq;
		for (i=0, fix=0; i<m; i++)
		{
			scanf("%d", &cmd);
			if (cmd == 1)
			{
				scanf("%lld", &t);
				pq.emplace(t-fix);
			}
			else if (cmd == 2)
			{
				scanf("%lld", &t);
				fix += t;
			}
			else
			{
				t = pq.top();
				pq.pop();
				printf("%lld\n", t+fix);
			}
		}
	}
	return 0;
}

