#include <iostream>
using namespace std;

int main()
{
	int n, i, t, first, second, fid, sid;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, first=0, second=0; i<n; i++)
		{
			scanf("%d", &t);
			if (t > first)
			{
				second = first;
				sid = fid;
				first = t;
				fid = i;
			}
			else if (t > second)
			{
				second = t;
				sid = i;
			}
		}
		printf("%d\n", sid+1);
	}
	return 0;
}

