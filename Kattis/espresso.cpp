#include <iostream>
using namespace std;

char buf[4];

int main()
{
	int n, m, i, cap, need, ans;
	scanf("%d%d", &n, &m);
	cap = m;
	for (i=0, ans=0; i<n; i++)
	{
		scanf("%s", buf);
		need = *buf - '0';
		if (buf[1] == 'L')
		{
			++need;
		}
		if (cap < need)
		{
			cap = m;
			++ans;
		}
		cap -= need;
	}
	printf("%d\n", ans);
	return 0;
}
