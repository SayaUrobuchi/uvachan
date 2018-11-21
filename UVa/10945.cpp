#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	char k[1000],x;
	a=0;
	while(scanf("%c",&x)==1)
	{
		if(x>64&&x<91)
		{
			k[a]=x;
			a++;
		}
		else if(x>96&&x<123)
		{
			k[a]=x-32;
			a++;
		}
		else if(x==10)
		{
			k[a]='\0';
			if(strcmp(k,"DONE")==0)
			{
				break;
			}
			for(b=0,c=a-1;b<=c;b++,c--)
			{
				if(k[b]!=k[c])
				{
					printf("Uh oh..\n");
					break;
				}
			}
			if(b>c)
			{
				printf("You won't be eaten!\n");
			}
			a=0;
		}
	}
	return 0;
}