#include <iostream>
#include <deque>
using namespace std;

char cmd[32];

int main()
{
	int m, i;
	deque<int> ll, rr;
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%s%d", cmd, &t);
		if (*cmd == 'g')
		{
			if (t < ll.size())
			{
				printf("%d\n", ll[t]);
			}
			else
			{
				printf("%d\n", rr[t-ll.size()]);
			}
		}
		else if (cmd[5] == 'b')
		{
			rr.push_back(t);
			if (rr.size() > ll.size())
			{
				ll.push_back(rr.front());
				rr.pop_front();
			}
		}
		else if (cmd[5] == 'f')
		{
			ll.push_front(t);
			if (ll.size() > rr.size() + 1)
			{
				rr.push_front(ll.back());
				ll.pop_back();
			}
		}
		else
		{
			if (ll.size() > rr.size())
			{
				rr.push_front(t);
			}
			else
			{
				ll.push_back(t);
			}
		}
	}
	return 0;
}
