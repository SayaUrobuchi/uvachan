#include <iostream>
using namespace std;

const int N = 1000005;
const int HEAD = 0;
const int TAIL = 1;

int ll[N], rr[N];
char cc[N];

int main()
{
	int t, i;
	string s;
	cin >> t;
	getline(cin, s);
	while (t--)
	{
		getline(cin, s);
		// HEAD <--> TAIL
		rr[HEAD] = TAIL;
		ll[TAIL] = HEAD;
		int cur = HEAD;
		int nxt_id = TAIL + 1;
		for (i=0; i<s.size(); i++)
		{
			if (s[i] == '<')
			{
				if (cur != HEAD)
				{
					int prev = ll[cur];
					rr[ prev ] = rr[cur];
					int next = rr[cur];
					ll[ next ] = ll[cur];
					cur = prev;
				}
			}
			else if (s[i] == '[')
			{
				cur = HEAD;
			}
			else if (s[i] == ']')
			{
				cur = ll[TAIL];
			}
			else
			{
				cc[ nxt_id ] = s[i];
				int prev = cur;
				int next = rr[cur];
				rr[ prev ] = nxt_id;
				ll[ next ] = nxt_id;
				rr[ nxt_id ] = next;
				ll[ nxt_id ] = prev;
				cur = nxt_id;
				nxt_id++;
			}
		}
		for (i=rr[HEAD]; i!=TAIL; i=rr[i])
		{
			cout << cc[i];
		}
		cout << "\n";
	}
	return 0;
}
