#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int len;

int* sum(int* str, int s)
{
	int *ptr, i;
	ptr = (int*)malloc(sizeof(int)*len);
	memset(ptr, 0, sizeof(int)*len);
	ptr[0] = s;
	/*printf("sum ");*/
	for(i=0; i<len-1; i++)
	{
		ptr[i] += str[i];
		if(ptr[i] > 9999999)
		{
			ptr[i+1] += ptr[i] / 10000000;
			ptr[i] %= 10000000;
		}
		/*printf("%d", ptr[i]);*/
	}
	/*printf("\n");*/
	return ptr;
}

int* pro(int* str, int s)
{
	int *ptr, i;
	ptr = (int*)malloc(sizeof(int)*len);
	memset(ptr, 0, sizeof(int)*len);
	/*printf("pro %d ", s);*/
	for(i=0; i<len-1; i++)
	{
		ptr[i] += str[i] * s;
		if(ptr[i] > 9999999)
		{
			ptr[i+1] += ptr[i] / 10000000;
			ptr[i] %= 10000000;
		}
		/*printf("%d", ptr[i]);*/
	}
	/*printf("\n");*/
	return ptr;
}

int* dec(int* str, int* s)
{
	int *ptr, i;
	ptr = (int*)malloc(sizeof(int)*len);
	memset(ptr, 0, sizeof(int)*len);
	for(i=0; i<len-1; i++)
	{
		ptr[i] += str[i] - s[i];
		if(ptr[i] < 0)
		{
			ptr[i] += 10000000;
			ptr[i+1]--;
		}
	}
	return ptr;
}

int comp(int* s1, int* s2)
{
	int i;
	for(i=len-1; i>-1; i--)
	{
		if(s1[i] > s2[i])
		{
			return 1;
		}
		else if(s1[i] < s2[i])
		{
			return -1;
		}
	}
	return 0;
}

int main()
{
	int count, i, j, *temp, *ary, *p, *s, *r;
	char str[1011];
	scanf("%d", &count);
	while(count--)
	{
		memset(str, 0, sizeof(str));
		scanf("%s", str);
		len = strlen(str)/7 + 10;
		temp = (int*)malloc(sizeof(int) * len);
		memset(temp, 0, sizeof(int)*len);
		ary = (int*)malloc(sizeof(int) * len);
		memset(ary, 0, sizeof(int)*len);
		if(strlen(str) % 2)
		{
			temp[0] = str[0] - 48;
			i = 2;
		}
		else
		{
			temp[0] = (str[0]-48)*10+str[1]-48;
			/*temp[0] = str[1] - 48;
			temp[1] = str[0] - 48;*/
			i = 3;
		}
		while(str[i-2])
		{
			for(j=1; j<10; j++)
			{
				if(comp(p=pro(s=sum(ary, j), j), temp) > 0)
				{
					free(p);
					free(s);
					break;
				}
				free(p);
				free(s);
			}
			temp = dec(s=temp, p=pro(r=sum(ary, j-1), j-1));
			free(r);
			free(p);
			free(s);
			printf("%d", j-1);
			ary = sum(s=ary, j+j-2);
			free(s);
			ary = pro(s=ary, 10);
			free(s);
			temp = pro(s=temp, 100);
			free(s);
			temp = sum(s=temp, (str[i-1]-48)*10 + str[i]-48);
			free(s);
			i += 2;
		}
		free(ary);
		free(temp);
		printf("\n");
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
