#include <stdio.h>
#include <string.h>

int main()
{
	int count, i, state, ary[3];
	char str[51];
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		gets(str);
		ary[0] = 0;
		ary[1] = 0;
		ary[2] = 0;
		for(i=0, state=0; str[i]; i++)
		{
			if(str[i] == 'M')
			{
				if(state || !ary[0])
				{
					break;
				}
				state++;
			}
			else if(str[i] == 'E')
			{
				if(state != 1 || !ary[1])
				{
					break;
				}
				state++;
			}
			else if(str[i] == '?')
			{
				ary[state]++;
			}
			else
			{
				break;
			}
		}
		if(state < 2 || str[i])
		{
			printf("no-theorem\n");
		}
		else
		{
			if(ary[2] - ary[1] == ary[0])
			{
				printf("theorem\n");
			}
			else
			{
				printf("no-theorem\n");
			}
		}
	}
	return 0;
}
