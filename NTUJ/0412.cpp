#include <stdio.h>
#include <string.h>

int hash[300000], res[1000000], num[1000000];
char s[1000000], buf[1000000];

int main()
{
	int cas, base, m, sl, ll, nl, i, j;
	char *ptr, *sp;
	cas = 0;
	while(gets(s))
	{
		for(ptr=s; *ptr&&*ptr==' '; ptr++);
		if(*ptr == 0)
		{
			continue;
		}
		for(ptr=s; *ptr==' '; ptr++);
		sp = ptr;
		for(ptr=s+strlen(s)-1; *ptr==' '; ptr--);
		*(++ptr) = 0;
		memset(hash, -1, sizeof(hash));
		for(ptr=sp, base=0; *ptr; ptr++)
		{
			if(*ptr > 32 && *ptr < 128)
			{
				hash[*ptr] = ptr-sp;
				base++;
			}
		}
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		while(gets(buf))
		{
			for(ptr=buf; *ptr&&*ptr==' '; ptr++);
			if(*ptr == 0)
			{
				break;
			}
			for(sp=buf; *sp==' '; sp++);
			for(ptr=buf+strlen(buf)-1; *ptr==' '; ptr--);
			*(ptr+1) = 0;
			if(hash[*sp] == -1)
			{
				printf("0\n");
				continue;
			}
			for(ptr=sp+1, m=hash[*sp]; *ptr; ptr++)
			{
				if(hash[*ptr] > m)
				{
					m = hash[*ptr];
				}
				else if(hash[*ptr] == -1)
				{
					break;
				}
			}
			if(*ptr)
			{
				printf("0\n");
				continue;
			}
			sl = ptr-sp;
			memset(res, 0, sizeof(res));
			ll = 1;
			for(++m; m<=base; m++)
			{
				memset(num, 0, sizeof(num));
				num[0] = 1;
				nl = 1;			
				for(i=sl-1; i>=0; i--)
				{
					for(j=0; j<nl; j++)
					{
						res[j] += num[j] * hash[sp[i]];
						if(res[j] >= 10)
						{
							res[j+1] += res[j] / 10;
							res[j] %= 10;
						}
					}
					for(; res[j]; j++)
					{
						if(res[j] >= 10)
						{
							res[j+1] += res[j] / 10;
							res[j] %= 10;
						}
					}
					if(j > ll)
					{
						ll = j;
					}
					for(j=0; j<nl; j++)
					{
						num[j] *= m;
					}
					for(j=0; j<nl; j++)
					{
						if(num[j] >= 10)
						{
							num[j+1] += num[j] / 10;
							num[j] %= 10;
						}
					}
					for(; num[j]; j++)
					{
						if(num[j] >= 10)
						{
							num[j+1] += num[j] / 10;
							num[j] %= 10;
						}
					}
					nl = j;
				}
			}
			for(i=ll-1; i>0&&res[i]==0; i--);
			for(; i>=0; i--)
			{
				printf("%d", res[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
