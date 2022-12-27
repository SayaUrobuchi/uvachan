#include <iostream>
#include <iomanip>
using namespace std;

const int TOTAL = 40;

int que[2048], got[64];

int main()
{
	int n, k, i, head, tail, tmp, nxt, cur, out;
	while (cin >> n >> k)
	{
		if (n == 0 && k == 0)
		{
			break;
		}
		for (i=1, tail=0; i<=n; i++, tail++)
		{
			que[tail] = i;
			got[i] = 0;
		}
		for (head=0, tmp=0, nxt=0; head<tail; head++)
		{
			if (tmp == 0)
			{
				nxt = (nxt % k) + 1;
				tmp += nxt;
			}
			cur = que[head];
			out = min(tmp, TOTAL-got[cur]);
			got[cur] += out;
			tmp -= out;
			if (got[cur] < TOTAL)
			{
				que[tail] = cur;
				tail++;
			}
			else
			{
				cout << setw(3) << cur;
			}
		}
		cout << "\n";
	}
	return 0;
}