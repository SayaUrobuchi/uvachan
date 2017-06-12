#include<stdio.h>
#include<string.h>
int abcc(char y)
{
	if(y>64)
	{
		return y-55;
	}
	return y-48;
}
int bcaa(int y)
{
	if(y>9)
	{
		return y+55;
	}
	return y+48;
}
int main()
{
	int a,b,c,d,f,g,h,j;
	unsigned long long e,i;
	char k[12],x,z[100];
	while(scanf("%d%d%c",&a,&b,&x)==3)
	{
		gets(k);
		c=strlen(k);
		for(c-=1,e=1,i=0;c>=0;c--,e*=a)
		{
			d=abcc(k[c]);
			if(d>=a)
			{
				printf("%s is an illegal base %d number\n",k,a);
				break;
			}
			i+=d*e;
		}
		if(c>=0)
		{
			continue;
		}
		if(b==10)
		{
			printf("%s base %d = %lld base %d\n",k,a,i,b);
			continue;
		}
		printf("%s base %d = ",k,a);
		if(i==0)
		{
			printf("0");
		}
		else
		{
			for(i,j=0;i>0;i/=b,j++)
			{
				z[j]=bcaa(i%b);
			}
			for(j-=1;j>=0;j--)
			{
				printf("%c",z[j]);
			}
		}
		printf(" base %d\n",b);
	}
	return 0;
}