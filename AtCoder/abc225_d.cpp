#include <iostream>
using namespace std;

const int N = 100005;

int c;
int ary[N];
int pre[N], nxt[N];

int find_head(int t)
{
	while (pre[t])
	{
		t = pre[t];
	}
	return t;
}

void get_list(int t)
{
	c = 0;
	while (t)
	{
		ary[c++] = t;
		t = nxt[t];
	}
}

int main()
{
	int n, m, i, j, a, b, cmd;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d", &cmd);
		if (cmd == 1)
		{
			scanf("%d%d", &a, &b);
			nxt[a] = b;
			pre[b] = a;
		}
		else if (cmd == 2)
		{
			scanf("%d%d", &a, &b);
			nxt[a] = 0;
			pre[b] = 0;
		}
		else
		{
			scanf("%d", &a);
			b = find_head(a);
			get_list(b);
			printf("%d", c);
			for (j=0; j<c; j++)
			{
				printf(" %d", ary[j]);
			}
			puts("");
		}
	}
	return 0;
}
