#include <iostream>
using namespace std;

const int N = 2000005;

int front[N], back[N];
int ans_list[N];

inline void conn(int a, int b)
{
	front[b] = a;
	back[a] = b;
}

int main()
{
	int count, n, m, i, t, st, a, b, c, cmd, ans;
	long long cnt;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &n, &m, &st);
		for (i=1; i<=n; i++)
		{
			front[i] = back[i] = -1;
		}
		conn(0, st);
		conn(st, n+1);
		for (i=0, cnt=0, ans=0; i<m; i++)
		{
			scanf("%d%d%d%d", &cmd, &a, &b, &c);
			if (cmd == 1)
			{
				if (c == 1)
				{
					b = front[b];
				}
				conn(a, back[b]);
				conn(b, a);
			}
			else if (cmd == 2)
			{
				conn(front[a], back[b]);
				conn(front[c], a);
				conn(b, c);
			}
			else
			{
				cnt += b;
				if (c == 1)
				{
					t = back[a];
					for (; b&&a; --b, a=front[a])
					{
						ans_list[ans] = a;
						++ans;
					}
					conn(a, t);
				}
				else
				{
					t = front[a];
					for (; b&&a<=n; --b, a=back[a])
					{
						ans_list[ans] = a;
						++ans;
					}
					conn(t, a);
				}
			}
		}
		printf("%lld\n", cnt-n);
		for (i=0; i<n; i++)
		{
			printf("%d\n", ans_list[i]);
		}
	}
	return 0;
}