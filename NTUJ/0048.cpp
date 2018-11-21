#include <stdio.h>
#include <string.h>

int ary[100000];
char tbl[128][100], s[100000], res[100000], temp[100000], *p, *q;

char search(char *ptr)
{
	int i;
	for(i=0; ; i++)
	{
		if(strcmp(tbl[i], ptr) == 0)
		{
			return i;
		}
	}
}

int main()
{
	int cas, count, m;
	cas = 0;
	strcpy(tbl['A'], ".-");
	strcpy(tbl['B'], "-...");
	strcpy(tbl['C'], "-.-.");
	strcpy(tbl['D'], "-..");
	strcpy(tbl['E'], ".");
	strcpy(tbl['F'], "..-.");
	strcpy(tbl['G'], "--.");
	strcpy(tbl['H'], "....");
	strcpy(tbl['I'], "..");
	strcpy(tbl['J'], ".---");
	strcpy(tbl['K'], "-.-");
	strcpy(tbl['L'], ".-..");
	strcpy(tbl['M'], "--");
	strcpy(tbl['N'], "-.");
	strcpy(tbl['O'], "---");
	strcpy(tbl['P'], ".--.");
	strcpy(tbl['Q'], "--.-");
	strcpy(tbl['R'], ".-.");
	strcpy(tbl['S'], "...");
	strcpy(tbl['T'], "-");
	strcpy(tbl['U'], "..-");
	strcpy(tbl['V'], "...-");
	strcpy(tbl['W'], ".--");
	strcpy(tbl['X'], "-..-");
	strcpy(tbl['Y'], "-.--");
	strcpy(tbl['Z'], "--..");
	strcpy(tbl['_'], "..--");
	strcpy(tbl[','], ".-.-");
	strcpy(tbl['.'], "---.");
	strcpy(tbl['?'], "----");
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", s);
		for(p=s, q=res, m=0; *p; p++)
		{
			strcpy(q, tbl[*p]);
			q += strlen(q);
			ary[m++] = strlen(tbl[*p]);
		}
		for(p=res, q=s, m--; m>=0; p+=ary[m--])
		{
			sprintf(temp, "%.*s\0", ary[m], p);
			*(q++) = search(temp);
		}
		*q = 0;
		printf("%d: %s\n", ++cas, s);
	}
	return 0;
}
