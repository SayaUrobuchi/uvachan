#include <stdio.h>
#include <string.h>

char buf[10005];

int main()
{
	int count, p, q, n;
	char *ptr;
	scanf("%d", &count);
	gets(buf);
	while(count--)
	{
		gets(buf);
		p = 0;
		q = 0;
		n = 0;
		ptr = strtok(buf, " ");
		if(ptr)
		{
			do
			{
				n++;
				if(*ptr == 'M')
				{
					p++;
				}
				else
				{
					q++;
				}
				if(*(ptr+1) == 'M')
				{
					q--;
				}
				else
				{
					p--;
				}
			}while(ptr = strtok(NULL, " "));
		}
		if(p || q || n == 1)
		{
			printf("NO LOOP\n");
		}
		else
		{
			printf("LOOP\n");
		}
	}
	return 0;
}
