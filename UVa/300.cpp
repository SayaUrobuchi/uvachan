#include <stdio.h>
#include <string.h>

char tbl[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", 
					"zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
char name[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", 
					 "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
char str[1000];

int mtod()
{
	int i;
	for(i=0; i<18; i++)
	{
		if(!strcmp(tbl[i], str))
		{
			break;
		}
	}
	return i * 20;
}

int main()
{
	int count, day, year, total;
	scanf("%d", &count);
	printf("%d\n", count);
	while(count--)
	{
		scanf("%d.%s%d", &day, str, &year);
		total = year * 365 + day + mtod();
		printf("%d %s %d\n", (total%260)%13+1, name[total%20], total/260);
	}
	return 0;
}
