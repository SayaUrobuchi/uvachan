#include <iostream>

char buf[1024];

int main()
{
	int count, i, t;
	long long ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", buf);
		for (i=0, ans=0, t=0; buf[i]; i++)
		{
			if (buf[i] == ',')
			{
				ans = (ans*60) + t;
				t = 0;
			}
			else
			{
				t = (t*10) + buf[i]-'0';
			}
		}
		ans = (ans*60) + t;
		printf("%lld\n", ans);
	}
	return 0;
}
