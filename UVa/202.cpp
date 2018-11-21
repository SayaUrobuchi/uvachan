#include<stdio.h>
#include<string.h>
int a,b,c,d,e,f,g,h,i,j,k[2000],l[2000];
int main()
{
	while(scanf("%d%d",&a,&b)==2)
	{
		printf("%d/%d = %d.",a,b,a/b);
		d=a%b;
		if(!d)
		{
			printf("(0)\n   1 = number of digits in repeating cycle\n\n");
			continue;
		}
		a=d;
		for(c=0;;c++)
		{
			a*=10;
			k[c]=a/b;
			a%=b;
			l[c]=a;
			for(d=0;d<c;d++)
			{
				if(k[d]==k[c]&&l[d]==l[c])
				{
					break;
				}
			}
			if(d<c)
			{
				break;
			}
		}
		for(e=0;e<d;e++)
		{
			printf("%d",k[e]);
		}
		printf("(");
		for(e=d,f=0;e<c;e++,f++)
		{
			if(f==50)
			{
				printf("...");
				break;
			}
			printf("%d",k[e]);
		}
		printf(")\n   %d = number of digits in repeating cycle\n\n",c-d);
	}
	return 0;
}