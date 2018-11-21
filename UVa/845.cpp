#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *p, const void *q)
{
	return *(char*)p - *(char*)q;
}

int main()
{
	int n, i, j, d;
	char buf[100], tbl[10], ch;
	while(gets(buf))
	{
		if(buf[0] == '.' && !buf[1])
		{
			break;
		}
		n = strlen(buf);
		for(i=0; i<10; i++)
		{
			tbl[i] = -1;
		}
		for(i=n-1, d=-1; i>-1; i--)
		{
			if((ch = buf[i]) == '.')
			{
				d = i;
			}
			else
			{
				ch -= 48;
				tbl[ch] = i;
				if(ch == 2)
				{
					tbl[5] = i;
				}
				else if(ch == 5)
				{
					buf[i] = '2';
					tbl[2] = i;
				}
				else if(ch == 6)
				{
					tbl[9] = i;
				}
				else if(ch == 9)
				{
					buf[i] = '6';
					tbl[6] = i;
				}
				for(j=ch+1; j<10; j++)
				{
					if(tbl[j] != -1)
					{
						break;
					}
				}
				if(j < 10)
				{
					buf[tbl[j]] = buf[i];
					buf[i] = j + 48;
					qsort(buf+i+1, n-i-1, sizeof(char), comp);
					if(d != -1)
					{
						for(j=i+1; j<d; j++)
						{
							buf[j] = buf[j+1];
							buf[j+1] = '.';
						}
					}
					break;
				}
			}
		}
		if(i == -1)
		{
			printf("The price cannot be raised.\n");
		}
		else
		{
			printf("%s\n", buf);
		}
	}
	return 0;
}
