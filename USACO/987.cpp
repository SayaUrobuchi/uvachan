#include <iostream>
using namespace std;

const int N = 128;

char buf[N];

int main()
{
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);
	int n, m, i;
	scanf("%d%d", &n, &m);
	int cur = 0;
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		string t = buf;
		if (cur + t.size() <= m)
		{
			if (cur)
			{
				putchar(' ');
			}
		}
		else
		{
			puts("");
			cur = 0;
		}
		cur += t.size();
		printf("%s", buf);
	}
	puts("");
	return 0;
}
