#include<stdio.h>
#include<string.h>
int a,b,c,d,e,f,g,h,j[1000];
char i[1000],k[1000];
int abcc()
{
	int x,y;
	if(b==a)
	{
		i[b]='\0';
		printf("%s\n",i);
		return 0;
	}
	for(x=0,y=0;x<a;x++)
	{
		if(k[x]!=y)
		{
			if(j[x]==0)
			{
				y=k[x];
				j[x]=1;
				i[b]=k[x];
				b++;
				abcc();
				b--;
				j[x]=0;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d%c",&g,&k[0]);
	for(h=0;h<g;h++)
	{
		gets(k);
		a=strlen(k);
		a--;
		for(b=0,d=a;b<a;b++,d--)
		{
			j[b]=0;
			for(c=0,f=0;c<d;c++)
			{
				if(k[c]>k[c+1])
				{
					f++;
					e=k[c];
					k[c]=k[c+1];
					k[c+1]=e;
				}
			}
			if(f==0)
			{
				break;
			}
		}
		a++;
		j[b]=0;
		b=0;
		c=0;
		abcc();
		printf("\n");
	}
	return 0;
}