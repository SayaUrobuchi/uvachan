#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	char k[61],x,y[61];
	c=0;
	d=0;
	while(gets(k))
	{
		if(strcmp(k,"#")==0)
		{
			break;
		}
		a=strlen(k);
		for(b=0;b<a;b++)
		{
			if(k[b]==32)
			{
				y[c]='\0';
				if(d==1)
				{
					printf("%s\n ",y);
					c=0;
					d=0;
					continue;
				}
				printf("%s ",y);
				c=0;
			}
			else if(k[b]>64&&k[b]<91)
			{
				y[c++]=k[b];
			}
			else if(k[b]>96&&k[b]<123)
			{
				y[c++]=k[b];
			}
			else if(k[b]=='-')
			{
				if(b==a-1)
				{
					d=1;
				}
			}
		}
		if(d==0)
		{
			y[c]='\0';
			printf("%s",y);
			c=0;
		}
		printf("\n");
	}
	return 0;
}