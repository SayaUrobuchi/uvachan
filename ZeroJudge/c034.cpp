#include<stdio.h>
#include<string.h>
	char x[10000],y,z;
	int a,b,c,d,e,f,g,h,i,j,k[10000];
int main()
{
	b=0;
	for(c=0;c<10000;c++)
	{
		k[c]=0;
	}
	while(scanf("%s", x) == 1/*gets(x)*/)
	{
		if(x[0]==48&&!x[1])
		{
			for(c=0;c<b;c++)
			{
				k[c+1]+=k[c]/10;
				k[c]%=10;
			}
			for(; k[c]; c++)
			{
				k[c+1]+=k[c]/10;
				k[c]%=10;
			}
			for(c--;c>=0;c--)
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
	return 0;
}
