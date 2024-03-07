#include <iostream>
using namespace std;
using pp = pair<int, int>;

const int N = 128;

int last[N], first[N];
char buf[N];

int main()
{
	int m, i, j;
	scanf("%d", &m);
	pp best = make_pair(0, 0);
	char ans;
	for (i=0; i<m; i++)
	{
		int pos;
		scanf("%d%s", &pos, buf);
		for (j=0; buf[j]; j++)
		{
			char cur = buf[j];
			if (last[cur])
			{
				pp dat = make_pair(pos - last[cur], -first[cur]);
				if (dat > best)
				{
					best = dat;
					ans = cur;
				}
			}
			else
			{
				first[cur] = pos;
			}
			last[cur] = pos;
		}
	}
	putchar(ans);
	puts("");
	return 0;
}
