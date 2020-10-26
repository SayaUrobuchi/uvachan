#include <iostream>

int trans(int n)
{
	int i, t, last, ans;
	for (i=0, last=0, ans=0; i<8; i++, n>>=1)
	{
		t = (n & 1);
		ans |= (t^last) << i;
		last = (t^last);
	}
	return ans;
}

int main()
{
	int n, i, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			if (i)
			{
				putchar(' ');
			}
			printf("%d", trans(t));
		}
		puts("");
	}
	return 0;
}
