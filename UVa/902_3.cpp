#include <stdio.h>
#include <algorithm>

char s[1048576];
long long ary[1048576];

int main()
{
	int n, i, j, m, mx;
	long long mod, t, ans;
	while (scanf("%d%s", &n, s) == 2)
	{
		for (i=0, t=0; i<n-1&&s[i]; i++)
		{
			t = (t<<5) + (s[i] - 'a');
		}
		mod = (1LL << (n*5-5)) - 1;
		for (m=0; s[i]; i++, m++)
		{
			t = ((t & mod) << 5) + (s[i] - 'a');
			ary[m] = t;
		}
		std::sort(ary, ary+m);
		for (i=0, mx=0; i<m; i=j)
		{
			for (j=i+1; j<m&&ary[j]==ary[i]; j++);
			if (j-i > mx)
			{
				mx = j-i;
				ans = ary[i];
			}
		}
		s[n] = 0;
		for (i=n-1; i>=0; i--, ans>>=5)
		{
			s[i] = (ans & 31) + 'a';
		}
		puts(s);
	}
	return 0;
}
