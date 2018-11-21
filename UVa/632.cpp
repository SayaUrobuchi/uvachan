#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, cmp;
int index[10000];
char buf[10000];
char str[10000];

int comp(const void *p, const void *q)
{
	/*cmp = strncmp(str+*(int*)p, str+*(int*)q, n);
	if(cmp)
	{
		return cmp;
	}
	return *(int*)p - *(int*)q;*/
	return strncmp(str+*(int*)p, str+*(int*)q, n);
}

int main()
{
	int count, i;
	char temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		gets(str);
		for(i=0; i<n; )
		{
			gets(str+i);
			i += strlen(str+i);
		}
		strcpy(buf, str);
		strcpy(str+n, buf);
		for(i=0; i<n; i++)
		{
			index[i] = i;
		}
		qsort(index, n, sizeof(int), comp);
		for(i=0; i<n; i++)
		{
			buf[i] = str[index[i]+n-1];
			if(index[i] == 1)
			{
				printf("%d\n", i);
			}
		}
		for(i=0; i<n; i+=50)
		{
			if(i + 50 >= n)
			{
				printf("%s\n", buf+i);
			}
			else
			{
				temp = buf[i+50];
				buf[i+50] = 0;
				printf("%s\n", buf+i);
				buf[i+50] = temp;
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
