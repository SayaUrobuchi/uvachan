#include <stdio.h>
#include <string.h>

int main()
{
	int count, f, line_n, word_n, char_n;
	char buf[1030], *p;
	gets(buf);
	for(p=buf, count=0; *p; p++)
	{
		count *= 10;
		count += *p - 48;
	}
	while(count--)
	{
		line_n = 0;
		word_n = 0;
		char_n = 0;
		while(gets(buf))
		{
			if(strcmp(buf, "=====") == 0)
			{
				break;
			}
			line_n++;
			for(p=buf, f=0; *p; p++)
			{
				if(*p == ' ' || *p == '\t')
				{
					word_n += f;
					f = 0;
				}
				else
				{
					f = 1;
				}
			}
			word_n += f;
			char_n += p-buf;
		}
		printf("%d %d %d\n", line_n, word_n, char_n);
	}
	return 0;
}
