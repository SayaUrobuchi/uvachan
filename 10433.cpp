#include <stdio.h>
#include <string.h>

int num[2001], res[4001];
char str[2001];

int main()
{
	int i, j, l, len, temp;
	char *ptr;
	while(gets(str))
	{
		len = strlen(str);
		if(str[len-1] != '5' && str[len-1] != '6')
		{
			printf("Not an Automorphic number.\n");
			continue;
		}
		for(i=len-4, l=0, ptr=str+i; ; i-=4, l++, ptr-=4)
		{
			if(i<=0)
			{
				ptr = str;
				if(i == -3)
				{
					sscanf(ptr, "%1d", &num[l]);
				}
				else if(i == -2)
				{
					sscanf(ptr, "%2d", &num[l]);
				}
				else if(i == -1)
				{
					sscanf(ptr, "%3d", &num[l]);
				}
				else
				{
					sscanf(ptr, "%4d", &num[l]);
				}
				l++;
				break;
			}
			sscanf(ptr, "%4d", &num[l]);
		}
		for(i=0, j=len-1; i<j; i++, j--)
		{
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
		}
		memset(res, 0, sizeof(res));
		for(i=0; i<l; i++)
		{
			for(j=0; j<l; j++)
			{
				res[i+j] += num[i] * num[j];
				if(res[i+j] > 9999)
				{
					res[i+j+1] += res[i+j] / 10000;
					res[i+j] %= 10000;
				}
			}
			for(; res[i+j]; j++)
			{
				if(res[i+j] > 9999)
				{
					res[i+j+1] += res[i+j] / 10000;
					res[i+j] %= 10000;
				}
			}
			temp = i+j;
		}
		/*printf("%d\n", temp);
		printf("%d", res[temp-1]);
		for(i=temp-2; i>-1; i--)
		{
			printf("%04d", res[i]);
		}
		printf("\n");*/
		for(i=0, l=0; i<temp; i++)
		{
			for(j=0; j<4&&l<len; j++, l++)
			{
				if(str[l] != res[i] % 10 + 48)
				{
					break;
				}
				res[i] /= 10;
			}
			if(j < 4)
			{
				break;
			}
		}
		if(l == len)
		{
			printf("Automorphic number of %d-digit.\n", l);
		}
		else
		{
			printf("Not an Automorphic number.\n");
		}
	}
	return 0;
}
