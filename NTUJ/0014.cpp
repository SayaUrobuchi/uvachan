#include <stdio.h>
#include <string.h>

int tbl[128], buf[32768];
char str[1300000], t[1300000], *ary[1300000], *stack[1300000];

int main()
{
	int cas, count, m, f;
	char *ptr, *p;
	int *q;
	cas = 0;
	gets(str);
	sscanf(str, "%d", &count);
	tbl['['] = tbl[']'] = tbl['+'] = tbl['-'] = tbl['>'] = tbl['<'] = tbl['.'] = 1;
	while(count--)
	{
		ptr = str;
		m = 0;
		f = 0;
		while(gets(t))
		{
			if(strcmp(t, "end") == 0)
			{
				*ptr = 0;
				break;
			}
			if(f == 0)
			{
				for(p=t; *p&&*p!='%'; p++)
				{
					if(tbl[*p])
					{
						if(*p == ']')
						{
							if(m == 0)
							{
								f = 1;
								break;
							}
							ary[ptr-str] = stack[--m];
							ary[stack[m]-str] = ptr;
						}
						else if(*p == '[')
						{
							stack[m++] = ptr;
						}
						*(ptr++) = *p;
					}
				}
			}
		}
		printf("PROGRAM #%d:\n", ++cas);
		if(f || m)
		{
			printf("COMPILE ERROR\n");
		}
		else
		{
			memset(buf, 0, sizeof(buf));
			for(ptr=str, q=buf; *ptr; ptr++)
			{
				if(*ptr == '>')
				{
					q++;
					if(q-buf >= 32768)
					{
						q -= 32768;
					}
				}
				else if(*ptr == '<')
				{
					q--;
					if(q-buf < 0)
					{
						q += 32768;
					}
				}
				else if(*ptr == '+')
				{
					(*q)++;
					if(*q >= 256)
					{
						*q -= 256;
					}
				}
				else if(*ptr == '-')
				{
					(*q)--;
					if(*q < 0)
					{
						*q += 256;
					}
				}
				else if(*ptr == '.')
				{
					putchar(*q);
				}
				else if(*ptr == '[')
				{
					if(*q == 0)
					{
						ptr = ary[ptr-str];
					}
				}
				else if(*ptr == ']')
				{
					if(*q)
					{
						ptr = ary[ptr-str];
					}
				}
			}
			putchar(10);
		}
	}
	return 0;
}
