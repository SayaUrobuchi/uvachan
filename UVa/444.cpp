#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	char k[900],x;
	a=0;
	while(scanf("%c",&k[a])==1)
	{
		if(k[a]==10)
		{
			if(k[0]>47&&k[0]<58)
			{
				for(b=a-1,x=0;b>=0;b--)
				{
					if(x>9)
					{
						if(x<13)
						{
							x*=10;
							x+=k[b]-48;
							printf("%c",x);
							x=0;
							continue;
						}
						printf("%c",x);
						x=k[b]-48;
						continue;
					}
					x*=10;
					x+=k[b]-48;
				}
				if(x>9)
				{
					printf("%c",x);
				}
				printf("\n");
				a=0;
				continue;
			}
			for(b=a-1;b>=0;b--)
			{
				for(c=k[b];c>0;c/=10)
				{
					printf("%d",c%10);
				}
			}
			printf("\n");
			a=0;
			continue;
		}
		a++;
	}
	return 0;
}