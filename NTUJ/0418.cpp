#include <stdio.h>

char s[200000], arr[1005][1005];

int main()
{
	int n, i, j, len, tl;
	char *ptr;
	while(scanf("%d", &n) == 1)
	{
		for(i=0, ptr=s; i<n; i++)
		{
			scanf("%s", ptr);
			for(; *ptr; ptr++);
		}
		len = ptr-s;
		tl = len / n;
		for(i=0; i<n; i++)
		{
			sprintf(arr[i], "%.*s", tl, s+tl*i);
		}
		for(i=0, ptr=s+len-1; i<tl; i++)
		{
			for(j=0; j<n; j++)
			{
				*(ptr--) = arr[j][i];
			}
		}
		for(ptr=s; *ptr; ptr++)
		{
			if(*ptr == '_')
			{
				*ptr = ' ';
			}
			if(*ptr == '\\')
			{
				*ptr = '\n';
			}
		}
		for(ptr=s+len-1; *ptr==' '; ptr--);
		*(++ptr) = '\n';
		*(++ptr) = 0;
		puts(s);
	}
	return 0;
}
