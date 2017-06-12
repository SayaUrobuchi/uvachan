#include <stdio.h>
#include <string.h>

int len, k;
int code[128];
int hash[128];
char ary[300][4];
char buf[2008];
char tbl[64][4] = {"Phe", "Ser", "Tyr", "Cys", 
				   "Phe", "Ser", "Tyr", "Cys", 
				   "Leu", "Ser", "", "", 
				   "Leu", "Ser", "", "Trp", 
				   "Leu", "Pro", "His", "Arg", 
				   "Leu", "Pro", "His", "Arg", 
				   "Leu", "Pro", "Gln", "Arg", 
				   "Leu", "Pro", "Gln", "Arg", 
				   "Ile", "Thr", "Asn", "Ser", 
				   "Ile", "Thr", "Asn", "Ser", 
				   "Ile", "Thr", "Lys", "Arg", 
				   "Met", "Thr", "Lys", "Arg", 
				   "Val", "Ala", "Asp", "Gly", 
				   "Val", "Ala", "Asp", "Gly", 
				   "Val", "Ala", "Glu", "Gly", 
				   "Val", "Ala", "Glu", "Gly", };

void deal(char *s)
{
	for(; *s; s++)
	{
		*s = code[*s];
	}
}

void reverse(char *s)
{
	int p, q, temp;
	for(p=0, q=len-1; p<q; p++, q--)
	{
		temp = s[p];
		s[p] = s[q];
		s[q] = temp;
	}
}

char *getstr(char *s)
{
	return tbl[(hash[*s]<<4)+hash[*(s+1)]+(hash[*(s+2)]<<2)];
}

int getans(char *s)
{
	int i, j;
	for(i=0; i+6<=len; i++)
	{
		if(s[i] == 'A' && s[i+1] == 'T' && s[i+2] == 'G')
		{
			for(j=i+3, k=0; j+3<=len; j+=3)
			{
				strcpy(ary[k], getstr(s+j));
				if(!ary[k][0])
				{
					return 1;
				}
				k++;
			}
			return 0;
		}
	}
	return 0;
}

void print()
{
	int i;
	printf("%s", ary[0]);
	for(i=1; i<k; i++)
	{
		printf("-%s", ary[i]);
	}
	printf("\n");
}

int main()
{
	code['A'] = 'T';
	code['T'] = 'A';
	code['C'] = 'G';
	code['G'] = 'C';
	hash['T'] = 0;
	hash['C'] = 1;
	hash['A'] = 2;
	hash['G'] = 3;
	while(gets(buf))
	{
		if(!strcmp(buf, "*"))
		{
			break;
		}
		len = strlen(buf);
		if(getans(buf))
		{
			print();
		}
		else
		{
			deal(buf);
			if(getans(buf))
			{
				print();
			}
			else
			{
				reverse(buf);
				if(getans(buf))
				{
					print();
				}
				else
				{
					deal(buf);
					if(getans(buf))
					{
						print();
					}
					else
					{
						printf("*** No translatable DNA found ***\n");
					}
				}
			}
		}
	}
	return 0;
}
