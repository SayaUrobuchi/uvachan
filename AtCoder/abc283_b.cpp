#include <iostream>
using namespace std;

const int CHANGE = 1;
const int N = 100005;

int ary[N];

int main()
{
	int n, m, i;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		int cmd;
		scanf("%d", &cmd);
		if (cmd == CHANGE)
		{
			int pos, val;
			scanf("%d%d", &pos, &val);
			ary[pos] = val;
		}
		else
		{
			int pos;
			scanf("%d", &pos);
			printf("%d\n", ary[pos]);
		}
	}
	return 0;
}
