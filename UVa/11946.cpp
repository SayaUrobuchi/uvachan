#include <stdio.h>

char s[150], has[128];

int main()
{
	int count, i;
	for(i=0; i<128; i++)
	{
		has[i] = i;
	}
	has['0'] = 'O';
	has['1'] = 'I';
	has['2'] = 'Z';
	has['3'] = 'E';
	has['4'] = 'A';
	has['5'] = 'S';
	has['6'] = 'G';
	has['7'] = 'T';
	has['8'] = 'B';
	has['9'] = 'P';
	gets(s);
	sscanf(s, "%d", &count);
	while(count--)
	{
		while(gets(s))
		{
			if(!(*s))
			{
				break;
			}
			for(i=0; s[i]; i++)
			{
				s[i] = has[s[i]];
			}
			printf("%s\n", s);
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
