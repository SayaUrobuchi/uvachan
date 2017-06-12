#include <stdio.h>
#include <string.h>

char s[1000000], buf[1000000], stemp[1000000];

int main()
{
	int i, j, l, l2;
	/*freopen("1.txt", "w", stdout);*/
	gets(s);
	l = strlen(s);
	if(!l)
	{
		printf("\n");
	}
	while(gets(buf))
	{
		for(j=l-1; j>=0&&s[j]==' '; j--);
		if(j < 0)
		{
			if(l > 0)
			{
				printf("\n");
			}
			l = 0;
			s[0] = 0;
		}
		if(l > 72)
		{
			for(; l>72; )
			{
				for(i=72; i>=0&&s[i]!=' '; i--);
				if(i < 0)
				{
					for(i=72; i<l&&s[i]!=' '; i++);
				}
				for(j=i-1; j>=0&&s[j]==' '; j--);
				s[j+1] = 0;
				printf("%s\n", s);
				if(i < l)
				{
					for(i++; s[i]==' '; i++);
				}
				strcpy(stemp, s+i);
				strcpy(s, stemp);
				l = strlen(s);
			}
		}
		for(i=0, l2=strlen(buf); i<l2&&buf[i]!=' '; i++);
		if(l && i && l2 && i+l < 72)
		{
			s[l++] = ' ';
			strcpy(s+l, buf);
			l = strlen(s);
		}
		else
		{
			if(l)
			{
				for(i=l-1; i>=0&&s[i]==' '; i--);
				s[i+1] = 0;
				printf("%s\n", s);
			}
			strcpy(s, buf);
			l = strlen(s);
			if(!l2)
			{
				printf("\n");
			}
		}
	}
	for(j=l-1; j>=0&&s[j]==' '; j--);
	if(j < 0)
	{
		if(l > 0)
		{
			printf("\n");
		}
		l = 0;
		s[0] = 0;
	}
	if(l > 72)
	{
		for(; l>72; )
		{
			for(i=72; i>=0&&s[i]!=' '; i--);
			if(i < 0)
			{
				for(i=72; i<l&&s[i]!=' '; i++);
			}
			for(j=i-1; j>=0&&s[j]==' '; j--);
			s[j+1] = 0;
			printf("%s\n", s);
			if(i < l)
			{
				for(i++; s[i]==' '; i++);
			}
			strcpy(stemp, s+i);
			strcpy(s, stemp);
			l = strlen(s);
		}
	}
	if(l)
	{
		for(i=l-1; i>=0&&s[i]==' '; i--);
		s[i+1] = 0;
		printf("%s\n", s);
	}
	return 0;
}
