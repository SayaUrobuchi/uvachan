#include <stdio.h>
#include <string.h>

int num[6];
int hash[500000];
char buf[2008];
char entext[2008];
char salt[2008];
char word[2008];
char ary[6][2008][6];

int uppercase(char *ptr)
{
	if(*ptr >= 'A' && *ptr <= 'Z')
	{
		*ptr += 32;
		return 1;
	}
	return 0;
}

int lowercase(char *ptr)
{
	return *ptr >= 'a' && *ptr <= 'z';
}

int getcode(char *s)
{
	int times, res;
	for(times=1, res=0; *s; s++, times*=26)
	{
		res += (*s-97) * times;
	}
	return res;
}

int exist(int c)
{
	int x, y;
	x = c >> 5;
	y = c % 32;
	if(!(hash[x] & (1 << y)))
	{
		hash[x] |= (1<<y);
		return 0;
	}
	return 1;
}

int main()
{
	int i, j, k, p, q, len, code;
	char *ptr, *p2;
	gets(entext);
	sprintf(salt, "%.2s\0", entext);
	while(gets(buf))
	{
		for(ptr=buf, p2=word; ; ptr++)
		{
			if(uppercase(ptr) || lowercase(ptr))
			{
				*(p2++) = *ptr;
			}
			else
			{
				len = p2 - word;
				if(len >= 2 && len <= 5)
				{
					*p2 = 0;
					code = getcode(word);
					if(!exist(code))
					{
						strcpy(ary[len][num[len]++], word);
					}
				}
				p2 = word;
				if(!(*ptr))
				{
					break;
				}
			}
		}
	}
	for(p=2, q=5; p<q; p++, q--)
	{
		for(i=0; i<num[p]; i++)
		{
			for(j=0; j<num[q]; j++)
			{
				for(k=0; k<10; k+=2)
				{
					if(k != 6)
					{
						sprintf(buf, "%s%d%s\0", ary[p][i], k, ary[q][j]);
						if(!strcmp(crypt(buf, salt), entext))
						{
							break;
						}
						sprintf(buf, "%s%d%s\0", ary[q][j], k, ary[p][i]);
						if(!strcmp(crypt(buf, salt), entext))
						{
							break;
						}
					}
				}
				if(k < 10)
				{
					break;
				}
			}
			if(j < num[q])
			{
				break;
			}
		}
		if(i < num[p])
		{
			break;
		}
	}
	puts(buf);
	return 0;
}
