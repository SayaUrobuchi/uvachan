#include <stdio.h>
#include <string.h>

long long tbl[30];
char str[1000];
char buf[1000];
char result[1000];

int main()
{
	int count, len, i, j, index;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%d", str, &index);
		index--;
		len = strlen(str);
		tbl[len-1] = 1;
		for(i=len-2, j=len; i>0; i--, j--)
		{
			if(tbl[i+1] > 2147483647)
			{
				tbl[i] = tbl[i+1];
			}
			else
			{
				tbl[i] = tbl[i+1] * j;
			}
		}
		result[0] = str[0];
		result[1] = 0;
		for(i=1; str[i]; i++)
		{
			for(j=0; index>=tbl[i]; j++, index-=tbl[i]);
			strcpy(buf, result+j);
			result[j] = str[i];
			result[j+1] = 0;
			strcat(result, buf);
		}
		printf("%s\n", result);
	}
	return 0;
}
