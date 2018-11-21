#include <stdio.h>

int ccc(int n, int k)
{
	int res, f, t, c, tn;
	if (n == 0)
	{
		return 0;
	}
	res = 0;
	f = 1;
	t = n;
	while (n > 0)
	{
		c = n%10;
		n /= 10;
		tn = (k ? n+1 : n);
		if (c > k)
		{
			res += tn * f;
		}
		else if (c == k)
		{
			res += (tn-1)*f + (t%f)+1;
		}
		else if (c < k)
		{
			res += (tn-1)*f;
		}
		f *= 10;
	}
	return res;
}

int main()
{
	int n, m, i;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		if (n > m)
		{
			n ^= m ^= n ^= m;
		}
		for (i=0; i<=9; i++)
		{
			if (i)
			{
				printf(" ");
			}
			printf("%d", ccc(m, i)-ccc(n-1, i));
		}
		puts("");
	}
    return 0;
}
