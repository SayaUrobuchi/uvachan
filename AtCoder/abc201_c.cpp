#include <iostream>
using namespace std;

char s[16];

int main()
{
	int i, j, t, res, appear, no, ans;
	while (scanf("%s", s) == 1)
	{
		for (i=0, appear=0, no=0; s[i]; i++)
		{
			if (s[i] == 'o')
			{
				appear |= (1 << i);
			}
			else if (s[i] == 'x')
			{
				no |= (1 << i);
			}
		}
		for (i=0, ans=0; i<10000; i++)
		{
			for (j=0, t=i, res=0; j<4; j++, t/=10)
			{
				res |= (1 << (t%10));
			}
			if ((res & appear) == appear)
			{
				if (!(res & no))
				{
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

