#include <stdio.h>

int ary[4];
char buf[16];

int main()
{
	int n, i, j, t;
	while (scanf("%d", &n) == 1)
	{
		ary[0] = ary[1] = 0;
		for (i=0; i<n; i++)
		{
			scanf("%s", buf);
			for (j=0; j<4; j++)
			{
				if (buf[j] == '0')
				{
					++ary[j>>1];
				}
			}
		}
		t = (ary[0]>ary[1]?ary[1]:ary[0])>>1;
		printf("%d %d %d\n", t, ary[0]-(t<<1), ary[1]-(t<<1));
	}
	return 0;
}
