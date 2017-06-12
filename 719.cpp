#include <stdio.h>
#include <string.h>

char buf[10005], str[20008];

int scomp(char *p, char *q, int l)
{
	int i;
	for(i=0; i<l; i++, p++, q++)
	{
		if(*p != *q)
		{
			return *p - *q;
		}
	}
	return 0;
}

int main()
{
	int count, i, j, l, maxnum, temp, ans, cmp;
	gets(buf);
	sscanf(buf, "%d", &count);
	while(count--)
	{
		gets(buf);
		l = strlen(buf);
		sprintf(str, "%s%s\0", buf, buf);
		for(i=0, maxnum=128; i<l; i++)
		{
			if(str[i] < maxnum)
			{
				maxnum = str[i];
				temp = i;
			}
		}
		for(i=temp, ans=i; i<l; ans=i)
		{
			for(j=i+1; j<l; )
			{
				for(; j<l&&str[j]!=str[i]||str[j]==str[j-1]; j++);
				if(j == l)
				{
					break;
				}
				for(; j<l; )
				{
					cmp = scomp(str+i, str+j, j-i);
					if(cmp == 0)
					{
						j += j-i;
					}
					else if(cmp > 0)
					{
						i = j;
						break;
					}
					else
					{
						j++;
						break;
					}
				}
				if(i == j)
				{
					break;
				}
			}
			if(j >= l)
			{
				break;
			}
		}
		printf("%d\n", ans+1);
	}
	return 0;
}
