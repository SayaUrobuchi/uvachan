#include <stdio.h>

int tbl[128];
char str[1000], stack[1000], final[1000];

int main()
{
	int sn;
	char *p, *q;
	tbl['+'] = tbl['-'] = 1;
	tbl['*'] = tbl['/'] = 2;
	while(gets(str))
	{
		for(p=str, q=final, sn=0; *p; p++)
		{
			if(tbl[*p])
			{
				for(sn--; sn>=0&&tbl[stack[sn]]>tbl[*p]; *(q++)=stack[sn--]);
				stack[++sn] = *p;
				sn++;
			}
			else if(*p == '(')
			{
				stack[sn++] = *p;
			}
			else if(*p == ')')
			{
				for(sn--; stack[sn]!='('; *(q++)=stack[sn--]);
			}
			else
			{
				*(q++) = *p;
			}
		}
		for(sn--; sn>=0; *(q++)=stack[sn--]);
		*q = 0;
		puts(final);
	}
	return 0;
}
