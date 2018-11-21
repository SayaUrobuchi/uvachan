#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

char ss[4][10][16] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, 
				{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, 
				{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, 
				{"", "M", "MM", "MMM", "IV", "V", "VI", "VII", "VIII", "IX"}};
char str[4000][20], buf[20], s1[20], s2[20];
map<string, int> has;

int main()
{
	int res, i, j;
	strcpy(str[0], "ZERO");
	has[str[0]] = 0;
	for(i=1; i<4000; i++)
	{
		sprintf(buf, "%04d", i);
		for(j=0; j<4; j++)
		{
			strcat(str[i], ss[3-j][buf[j]-'0']);
		}
		has[str[i]] = i;
	}
	while(scanf("%s%s", s1, s2) == 2)
	{
		if(s1[0] == '#')
		{
			break;
		}
		res = has[s1]-has[s2];
		if(res < 0)
		{
			res = -res;
		}
		printf("%s\n", str[res]);
	}
	return 0;
}
