#include <stdio.h>
#include <string.h>

int main()
{
	int in;
	char ans[100], buf[100];
	while(scanf("%d", &in) == 1)
	{
		if(in < 0) break;
		if(in < 3) printf("%d\n", in);
		else
		{
			ans[0] = 0;
			while(in)
			{
				sprintf(buf, "%d%s", in % 3, ans);
				in /= 3;
				strcpy(ans, buf);
			}
			puts(ans);
		}
	}
	return 0;
}
