#include<iostream>
using namespace std;

int stk[1048576];

int main()
{
	int n, i, t, sn;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, sn=0; i<n; i++)
		{
			scanf("%d", &t);
			if (sn && (stk[sn-1]&1) == (t&1))
			{
				--sn;
			}
			else
			{
				stk[sn++] = t;
			}
		}
		printf("%d\n", sn);
	}
	return 0;
}
