#include <stdio.h>
#include <string.h>

int al, bl, fl;
int used[16][65536];
int queue[1500000];
int qlen[1500000];
char as[1005], bs[1005], final[1005];
char buf[1005], buf2[1005], buf3[1005];

int getcode(char *s)
{
	int i, res;
	for(i=0, res=0; s[i]; i++)
	{
		if(s[i] == 'b')
		{
			res += 1 << i;
		}
	}
	return res;
}

char *getstr(int now, int l)
{
	int i;
	for(i=0; i<l; i++)
	{
		if(now & (1 << i))
		{
			buf3[i] = 'b';
		}
		else
		{
			buf3[i] = 'a';
		}
	}
	buf3[i] = 0;
	return buf3;
}

int check(char *t, int l)
{
	int i, j;
	if(l < fl)
	{
		return 0;
	}
	for(i=0; i+fl<=l; i++)
	{
		for(j=0; j<fl; j++)
		{
			if(final[j] != t[i+j])
			{
				break;
			}
		}
		if(j == fl)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int n, i, j, p, q, temp, now, len;
	char *ptr, *ptr2;
	while(gets(as))
	{
		al = strlen(as);
		gets(bs);
		bl = strlen(bs);
		gets(buf);
		gets(final);
		fl = strlen(final);
		if(check(buf, strlen(buf)))
		{
			printf("YES\n");
			continue;
		}
		memset(used, 0, sizeof(used));
		for(i=0, n=0; buf[i]; i++)
		{
			for(j=0; buf[i+j]; j++)
			{
				buf2[j] = buf[i+j];
				buf2[j+1] = 0;
				if(!used[j][temp=getcode(buf2)])
				{
					used[j][temp] = 1;
					queue[n] = temp;
					qlen[n++] = j + 1;
				}
			}
		}
		for(i=0, j=n; i<j; i++)
		{
			now = queue[i];
			len = qlen[i];
			ptr = getstr(now, len);
			ptr2 = buf;
			for(p=0; ptr[p]; p++)
			{
				if(ptr[p] == 'a')
				{
					strcpy(ptr2, as);
				}
				else
				{
					strcpy(ptr2, bs);
				}
				ptr2 += strlen(ptr2);
			}
			/*printf("%s => %s\n", ptr, buf);*/
			len = strlen(buf);
			if(check(buf, len))
			{
				break;
			}
			for(p=0; p<len; p++)
			{
				for(q=0; p+q<len&&q<fl; q++)
				{
					buf2[q] = buf[p+q];
					buf2[q+1] = 0;
					/*printf("%s\n", buf2);*/
					if(!used[q][temp=getcode(buf2)])
					{
						used[q][temp] = 1;
						queue[j] = temp;
						qlen[j++] = q + 1;
					}
				}
			}
		}
		if(i == j)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
