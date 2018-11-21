#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[30];
	char x;
	a=0;
	for(b=0;b<30;b++)
	{
		k[b]=0;
	}
	b=0;
	while(scanf("%c",&x)==1)
	{
		if(x=='#')
		{
			for(a=1;a<30;a++)
			{
				if(k[a]>0)
				{
					printf("%d %d\n",a,k[a]);
					k[a]=0;
				}
			}
			a=0;
			b=0;
			printf("\n");
		}
		else if(x=='\''||x=='-')
		{
			b=1;
			continue;
		}
		else if(x>64&&x<91)
		{
			a++;
			b=0;
		}
		else if(x>96&&x<123)
		{
			a++;
			b=0;
		}
		else if(x==10)
		{
			if(b==1)
			{
				continue;
			}
			k[a]++;
			a=0;
		}
		else
		{
			b=0;
			k[a]++;
			a=0;
		}
	}
	return 0;
}