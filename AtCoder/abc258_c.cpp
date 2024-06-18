#include <iostream>
using namespace std;

const int N = 500005;

char s[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	int cur = 0;
	for (i=0; i<m; i++)
	{
		int cmd, t;
		scanf("%d%d", &cmd, &t);
		if (cmd == 1)
		{
			cur = (cur + n - t) % n;
		}
		else
		{
			printf("%c\n", s[(cur+t-1)%n]);
		}
	}
	return 0;
}
