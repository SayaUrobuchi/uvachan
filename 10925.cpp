#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i[25],j[25];
	char k[25];
	h=0;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a==0&&b==0)
		{
			break;
		}
		gets(k);
		for(c=0;c<25;c++)
		{
			j[c]=0;
		}
		for(a;a>0;a--)
		{
			gets(k);
			c=strlen(k);
			for(c-=1,d=0;c>-1;c--,d++)
			{
				j[d]+=k[c]-48;
			}
		}
		for(a=0;a<24;a++)
		{
			j[a+1]+=j[a]/10;
			j[a]%=10;
		}
		for(a=24;a>-1;a--)
		{
			if(j[a]!=0)
			{
				e=a;
				break;
			}
		}
		for(c=0,d=0;a>-1;a--)
		{
			c*=10;
			c+=j[a];
			i[d++]=c/b;
			c%=b;
		}
		for(c=0;i[c]==0&&c<d;c++)
		{
		}
		if(c==d)
		{
			c--;
		}
		printf("Bill #%d costs ",++h);
		for(e;e>-1;e--)
		{
			printf("%d",j[e]);
		}
		printf(": each friend should pay ");
		for(c;c<d;c++)
		{
			printf("%d",i[c]);
		}
		printf("\n\n");
	}
	return 0;
}