#include<stdio.h>
#include<string.h>
int main()
{
	char x[100],y,z;
	int a,b,c,d,e,f,g,h,i,j,k[100];
	b=0;
	for(c=0;c<100;c++)
	{
		k[c]=0;
	}
	while(gets(x))
	{
		if(x[0]==48)
		{
			for(c=0;c<b;c++)
			{
				k[c+1]+=k[c]/10;
				k[c]%=10;
				if(k[c+1]!=0)
				{
					b=c+2;
				}
			}
			for(c=b-1;c>=0;c--)
			{
				printf("%d",k[c]);
			}
			printf("\n");
			break;
		}
		else
		{
			a=strlen(x);
			for(c=a-1,d=0;c>=0;c--,d++)
			{
				k[d]+=x[c];
				k[d]-=48;
			}
			if(a>b)
			{
				b=a;
			}
		}
	}
}