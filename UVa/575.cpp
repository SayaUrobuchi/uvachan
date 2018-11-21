#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	char k[45];
	while(gets(k))
	{
		a=strlen(k);
		if(strcmp(k,"0")==0)
		{
			break;
		}
		for(a-=1,b=2,c=0;a>-1;a--,b*=2)
		{
			c+=(k[a]-48)*(b-1);
		}
		printf("%d\n",c);
	}
	return 0;
}