#include <stdio.h>
#include <string.h>

char str[100005], list[100005];

int is_pal(int i, int j)
{
	if(i > j)
	{
		return 1;
	}
	if(str[i] == str[j])
	{
		return is_pal(i+1, j-1);
	}
	return 0;
}

int main()
{
	int i, j, len;
	while(gets(str))
	{
		len = strlen(str);
		for(i=0, j=0; str[i]; i++)
		{
			if(str[i] != str[len-1])
			{
				list[j++] = str[i];
			}
			else
			{
				if(is_pal(i+1, len-2))
				{
					break;
				}
				list[j++] = str[i];
			}
		}
		printf("%s", str);
		for(i=j-1; i>=0; i--)
		{
			printf("%c", list[i]);
		}
		printf("\n");
	}
	return 0;
}
