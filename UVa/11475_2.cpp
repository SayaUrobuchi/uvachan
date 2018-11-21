#include <stdio.h>
#include <string.h>

int next[100005];
char str[100005], ts[100005];

int main()
{
	int len, i, j;
	while(gets(str))
	{
		len = strlen(str);
		for(i=0; i<len; i++)
		{
			ts[i] = str[len-i-1];
		}
		ts[len] = 0;
		next[0] = -1;
		for(i=0, j=-1; i<len; i++, j++, next[i]=j)
		{
			while(j>=0 && ts[i]!=ts[j])
			{
				j = next[j];
			}
		}
		for(i=0, j=0; i<len; i++, j++)
		{
			while(j>=0 && str[i]!=ts[j])
			{
				j = next[j];
			}
		}
		printf("%s%s\n", str, ts+j);
	}
	return 0;
}
