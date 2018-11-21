#include <stdio.h>
#include <string.h>

char buf[100];

char* inc(int len)
{
	int i;
	char *ptr;
	ptr = buf;
	i = 0;
	while(scanf("%1d", &ptr[i])==1)
	{
		i++;
		if(i == len) break;
	}
	ptr[i] = 0;
	return ptr;
}

int trans(char* str, int len)
{
	int i, num;
	num = 0;
	for(i=0; i<len; i++)
	{
		num *= 2;
		num += str[i];
	}
	return num;
}

int main()
{
	int i, num, len, bi[8], pre[8];
	char header[1000], *str;
	bi[0] = 1;
	pre[0] = 0;
	for(i=1; i<8; i++) bi[i] = bi[i-1] * 2;
	for(i=1; i<8; i++) pre[i] = pre[i-1] + bi[i] - 1;
	while(gets(header))
	{
		str = inc(3);
		len = trans(str, 3);
		while(len)
		{
			str = inc(len);
			num = trans(str, len);
			while(num != bi[len] - 1)
			{
				printf("%c", header[num + pre[len-1]]);
				str = inc(len);
				num = trans(str, len);
			}
			str = inc(3);
			len = trans(str, 3);
		}
		printf("\n");
		gets(header);
	}
	return 0;
}
