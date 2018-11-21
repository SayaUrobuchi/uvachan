#include <stdio.h>

long long ab(long long now)
{
	return now < 0 ? -now : now;
}

int main()
{
	int count;
	long long a, b, c;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%I64d%I64d%I64d", &a, &b, &c);
		if(a>0 && b>0 && c>0 && (ab(a*a-b*b)==c*c || ab(a*a-c*c)==b*b || ab(b*b-c*c)==a*a))
		{
			puts("yes");
		}
		else
		{
			puts("no");
		}
	}
	return 0;
}
