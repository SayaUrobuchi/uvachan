#include <stdio.h>
#include <algorithm>

char s[16];
long long ary[1048576];

int main()
{
	int n, i, j, m, mx, c;
	long long mod, t, ans;
	while ((c = getchar()) != EOF)
	{
		for (; c<'0'||c>'9'; c=getchar())
		{
			if (c == EOF)
			{
				exit(0);
			}
		}
		for (n=c-'0', c=getchar(); c>='0'&&c<='9'; n=n*10+c-'0', c=getchar());
		for (; c<'a'||c>'z'; c=getchar());
		for (i=0, t=0; i<n-1; i++, c=getchar())
		{
			t = (t<<5) + (c - 'a');
		}
		mod = (1LL << (n*5-5)) - 1;
		for (m=0; c>='a'&&c<='z'; m++, c=getchar())
		{
			t = ((t & mod) << 5) + (c - 'a');
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
