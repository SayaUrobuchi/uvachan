#include <stdio.h>
#include <unordered_map>

char spd[] = { 'C', 'D', 'H', 'S' };
char num[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
char str[52][4];
std::unordered_map<std::string, int> tbl;

int main()
{
	int i, j, id;
	char s1[4], s2[4];
	char buf[8];
	for (i=0; i<4; i++)
	{
		for (j=0; j<13; j++)
		{
			sprintf(str[i+j*4], "%c %c", spd[i], num[j]);
			tbl[str[i+j*4]] = i+j*4;
		}
	}
	scanf("%s%s", s1, s2);
	sprintf(buf, "%s %s", s1, s2);
	id = tbl[buf];
	if (id+1 < 52)
	{
		puts(str[id+1]);
	}
	else
	{
		puts("IMPOSSIBLE");
	}
	return 0;
}
