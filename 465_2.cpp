#include <stdio.h>
#include <string.h>

#define M 2147483647

char s[1048576];

int main()
{
	int f0, f1, f2, op;
	char *p1, *p2, *q, *r;
	long long v0, v1, v2;
	while (gets(s))
	{
		puts(s);
		f0 = f1 = f2 = 0;
		op = 0;
		p1 = s;
		for (; *p1=='0'&&*(p1+1)>='0'&&*(p1+1)<='9'; p1++);
		q = p1;
		for (; *q>='0'&&*q<='9'; q++);
		r = q;
		for (; *r!='*'&&*r!='+'; r++);
		if (*r == '*')
		{
			op = 1;
		}
		*q = 0;
		for (r++; *r<'0'||*r>'9'; r++);
		p2 = r;
		for (; *p2=='0'&&*(p2+1)>='0'&&*(p2+1)<='9'; p2++);
		if (strlen(p1) > 10)
		{
			f1 = 1;
		}
		else
		{
			sscanf(p1, "%lld", &v1);
			if (v1 > M)
			{
				f1 = 1;
			}
		}
		if (strlen(p2) > 10)
		{
			f2 = 1;
		}
		else
		{
			sscanf(p2, "%lld", &v2);
			if (v2 > M)
			{
				f2 = 1;
			}
		}
		if ((f1 && (!op || f2 || v2)) || (f2 && (!op || f1 || v1)))
		{
			f0 = 1;
		}
		else
		{
			if (op)
			{
				v0 = v1 * v2;
			}
			else
			{
				v0 = v1 + v2;
			}
			if (v0 > M)
			{
				f0 = 1;
			}
		}
		if (f1)
		{
			puts("first number too big");
		}
		if (f2)
		{
			puts("second number too big");
		}
		if (f0)
		{
			puts("result too big");
		}
	}
	return 0;
}
