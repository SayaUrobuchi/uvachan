#include <stdio.h>
#include <string.h>

int num[1001], res[1001];
char str[1001], buf[5000];

int main()
{
	int i, j, k, l, p, len;
	while(gets(str))
	{
		if(str[0] == '-')
		{
			break;
		}
		len = strlen(str);
		if(len == 1)
		{
			printf("1%s\n", str);
			continue;
		}
		for(i=len-8, j=0; ; i-=8, j++)
		{
			if(i < 0)
			{
				if(i == -8)
				{
					break;
				}
				sscanf(str, "%d", &num[j]);
				j++;
				break;
			}
			sscanf(str+i, "%d", &num[j]);
			str[i] = 0;
		}
		l = j;
		for(i=9, p=0; i>1; )
		{
			for(j=l-1, k=0; j>-1; j--)
			{
				k *= 100000000;
				k += num[j];
				res[j] = k / i;
				k %= i;
			}
			if(k)
			{
				i--;
			}
			else
			{
				buf[p++] = i + 48;
				if(!res[l-1])
				{
					l--;
				}
				for(j=0; j<l; j++)
				{
					num[j] = res[j];
				}
				if(!l)
				{
					break;
				}
			}
		}
		if(l == 1 && num[0] == 1)
		{
			for(i=p-1; i>-1; i--)
			{
				printf("%c", buf[i]);
			}
			printf("\n");
		}
		else
		{
			printf("There is no such number.\n");
		}
	}
	return 0;
}
