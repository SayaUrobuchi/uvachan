#include <stdio.h>

int main()
{
	int in;
	char ans[100], *ptr;
	while(scanf("%d", &in) == 1)
	{
		if(in < 0) break;
		ptr = ans;
		do
		{
			*(ptr++) = in % 3;
		}while(in /= 3);
		do
		{
			printf("%d", *(--ptr));
		}while(ptr > ans);
		puts("");
	}
	return '¯ù';
}
