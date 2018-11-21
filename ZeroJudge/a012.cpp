#include <stdio.h>
#include <string.h>

char str[4000][100];
char digit[4][10][10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", 
					 "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", 
					 "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", 
					 "", "M", "MM", "MMM", "", "", "", "", "", ""};

char s1[100], s2[100];

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int getnum(char* s)
{
	int i;
	for(i=1; i<4000; i++)
	{
		if(!strcmp(str[i], s))
		{
			return i;
		}
	}
	return 0;
}

int main()
{
	int i, j, num1, num2;
	strcpy(str[0], "ZERO");
	for(i=1; i<4000; i++)
	{
		sprintf(s1, "%04d", i);
		for(j=0; j<4; j++)
		{
			strcat(str[i], digit[3-j][s1[j]-48]);
		}
	}
	while(scanf("%s%s", s1, s2) == 2)
	{
		if(!strcmp(s1, "#"))
		{
			break;
		}
		num1 = getnum(s1);
		num2 = getnum(s2);
		puts(str[ab(num1-num2)]);
	}
	return 0;
}
