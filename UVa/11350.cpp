#include <stdio.h>

char str[100];

int main()
{
	int count, i;
	long long p, q, r, s, t, u;
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		gets(str);
		for(i=0, p=0, q=1, r=1, s=1, t=1, u=0; str[i]; i++)
		{
			if(str[i] == 'L')
			{
				t = r;
				u = s;
			}
			else
			{
				p = r;
				q = s;
			}
			r = p + t;
			s = q + u;
		}
		printf("%lld/%lld\n", r, s);
	}
	return 0;
}
