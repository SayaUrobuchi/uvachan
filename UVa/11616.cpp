#include <stdio.h>
#include <string.h>

char dig[4][10][5] = {
	{"", "M", "MM", "MMM", "", "", "", "", "", ""}, 
	{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, 
	{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, 
	{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
};
char roma[4000][32];
char s[32];

int main()
{
	int i, j, k;
	char *p;
	for (i=1; i<4000; i++)
	{
		p = roma[i];
		sprintf(s, "%04d", i);
		for (j=0; j<4; j++)
		{
			strcpy(p, dig[j][s[j]-'0']);
			p += strlen(p);
		}
	}
	while (gets(s))
	{
		if (*s >= '0' && *s <= '9')
		{
			sscanf(s, "%d", &i);
			puts(roma[i]);
		}
		else
		{
			for (i=1; i<4000; i++)
			{
				if (!strcmp(s, roma[i]))
				{
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}
