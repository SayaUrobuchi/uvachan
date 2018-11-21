#include <stdio.h>

char s[100005];

int main()
{
	int f, t;
	char *p;
	while(gets(s))
	{
		if(*s == '*' && !(*(s+1)))
		{
			break;
		}
		f = 0;
		t = 0;
		for(p=s; *p; p++)
		{
			if((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))
			{
				if(!t)
				{
					if(!f)
					{
						f = (*p|32);
					}
					if((*p|32) != f)
					{
						break;
					}
				}
				t = 1;
			}
			else
			{
				t = 0;
			}
		}
		if(*p)
		{
			printf("N\n");
		}
		else
		{
			printf("Y\n");
		}
	}
	return 0;
}
