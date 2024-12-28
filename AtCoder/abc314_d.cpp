#include <iostream>
using namespace std;

const int N = 500005;

int flag[N];
char s[N];

int main()
{
	int n, m, i;
	scanf("%d%s%d", &n, s, &m);
	int last = -1;
	bool upper;
	for (i=1; i<=m; i++)
	{
		int cmd, pos;
		char ch;
		scanf("%d%d %c", &cmd, &pos, &ch);
		if (cmd == 1)
		{
			--pos;
			s[pos] = ch;
			flag[pos] = i;
		}
		else
		{
			last = i;
			upper = (cmd == 3);
		}
	}
	for (i=0; i<n; i++)
	{
		if (flag[i] > last)
		{
			putchar(s[i]);
		}
		else
		{
			if (upper)
			{
				putchar(s[i] & ~32);
			}
			else
			{
				putchar(s[i] | 32);
			}
		}
	}
	puts("");
	return 0;
}
