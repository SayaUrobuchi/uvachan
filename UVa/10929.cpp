#include<stdio.h>
#include<string.h>
int main()
{
	char k[1001];
	int a,b,c,d;
	while(gets(k))
	{
		d=strlen(k);
		if(k[0]==48&&d==1)
		{
			break;
		}
		for(a=0,b=1,c=0;a<d;a++)
		{
			c+=(k[a]-48)*b;
			b*=-1;
		}
		if(c%11==0)
		{
			printf("%s is a multiple of 11.\n",k);
		}
		else
		{
			printf("%s is not a multiple of 11.\n",k);
		}
	}
	return 0;
}