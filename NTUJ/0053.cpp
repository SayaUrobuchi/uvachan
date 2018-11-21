#include <stdio.h>
#include <string.h>

int ary[1000];
char buf[1000], str[1000];

int main()
{
	int i, j, k, l;
	while(scanf("%s", buf) == 1)
	{
		l = strlen(buf);
		for(i=1; i<=l; i++)
		{
			memset(ary, 0, sizeof(ary));
			for(j=0; j<l; j++)
			{
				ary[j] = (buf[l-j-1]-48) * i;
			}
			for(j=0; j<l; j++)
			{
				if(ary[j] >= 10)
				{
					ary[j+1] += ary[j] / 10;
					ary[j] %= 10;
				}
			}
			for(; ary[j]; j++)
			{
				if(ary[j] >= 10)
				{
					ary[j+1] += ary[j] / 10;
					ary[j] %= 10;
				}
			}
			for(k=0; k<j; k++)
			{
				str[j-k-1] = str[j+j-k-1] = ary[k] + 48;
			}
			str[j+j] = 0;
			for(k=0; k<j; k++)
			{
				if(strncmp(str+k, buf, l) == 0)
				{
					break;
				}
			}
			if(k >= j)
			{
				break;
			}
			/*puts(str);*/
		}
		if(i > l)
		{
			printf("%s is cyclic\n", buf);
		}
		else
		{
			printf("%s is not cyclic\n", buf);
		}
	}
	return 0;
}
