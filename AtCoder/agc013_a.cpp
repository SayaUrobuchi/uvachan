#include <iostream>
using namespace std;

int main()
{
	int n, i, t, typ, last, ans;
	scanf("%d%d", &n, &last);
	for (i=1, ans=1, typ=0; i<n; i++)
	{
		scanf("%d", &t);
		if (typ)
		{
			if ((long long)(t-last) * typ < 0)
			{
				typ = 0;
				++ans;
			}
		}
		else
		{
			typ = t - last;
		}
		last = t;
	}
	printf("%d\n", ans);
	return 0;
}