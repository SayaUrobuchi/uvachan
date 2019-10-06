#include <stdio.h>
#include <string.h>

char s0[1024], s1[1024];

int main()
{
	int d0, d1, ans;
	while (scanf("%s%d%s%d", s0, &d0, s1, &d1) == 4)
	{
		ans = 0;
		if (strcmp(s0, s1) == 0)
		{
			++ans;
		}
		if (d0 == d1)
		{
			++ans;
		}
		puts(ans?(ans==1?"=~=":"GOOD"):"OTZ");
	}
	return 0;
}
