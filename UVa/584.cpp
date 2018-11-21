#include <stdio.h>
#include <string.h>

char buf[2008];

int main()
{
	int turn, score, bonus, temp;
	char *ptr;
	while(gets(buf))
	{
		if(!strcmp(buf, "Game Over"))
		{
			break;
		}
		for(ptr=buf, score=0, turn=0, bonus=0; turn<10; turn++, ptr+=2, bonus/=3)
		{
			if(*ptr == 'X')
			{
				score += 10 * (bonus%3);
				bonus += 3 + 9;
				score += 10;
			}
			else
			{
				temp = *ptr - '0';
				score += temp * (bonus%3);
				/*printf("XD %d\n", temp * (bonus%3));*/
				score += temp;
				bonus /= 3;
				ptr += 2;
				if(*ptr == '/')
				{
					temp = 10 - temp;
					score += temp * (bonus%3);
					/*printf("XD %d\n", temp * (bonus%3));*/
					score += temp;
					bonus += 3;
				}
				else
				{
					temp = *ptr - '0';
					score += temp * (bonus%3);
					/*printf("XD %d\n", temp * (bonus%3));*/
					score += temp;
				}
			}
			/*printf("%d\n", score);*/
		}
		for(; bonus; ptr+=2, bonus/=3)
		{
			if(*ptr == 'X')
			{
				temp = 10;
			}
			else if(*ptr == '/')
			{
				temp = 10 - temp;
			}
			else
			{
				temp = *ptr - '0';
			}
			score += temp * (bonus%3);
		}
		printf("%d\n", score);
	}
	return 0;
}
