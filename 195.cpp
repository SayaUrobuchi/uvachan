#include<stdio.h>
#include<string.h>
char k[200],x,y[200];
int a,b,c,g[200],i;
int abcc()
{
	int j;
	for(j=0;j<a;j++)
	{
		//printf("111 %d\n",j);
		if(g[j]!=-1)
		{
			if(j>0)
			{
				if(k[j]==k[j-1]&&g[j-1]!=-1)
				{
					//printf("333 %d\n",j);
					continue;
				}
			}
			if(b==a-1)
			{
				for(c=0;c<a-1;c++)
				{
					printf("%c",y[c]);
				}
				printf("%c\n",k[j]);
			}
			else
			{
				y[b]=k[j];
				g[j]=-1;
				b++;
				abcc();
				b--;
				g[j]=0;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d%c",&i,&x);
	for(i;i>0;i--)
	{
		gets(k);
		a=strlen(k);
		for(b=0;b<a;b++)
		{
			if(k[b]<97)
			{
				g[b]=k[b];
				g[b]-=64;
				g[b]*=2;
				g[b]--;
			}
			else
			{
				g[b]=k[b];
				g[b]-=96;
				g[b]*=2;
			}
		}
		for(b=0;b<a-1;b++)
		{
			for(c=0;c<a-1;c++)
			{
				if(g[c]>g[c+1])
				{
					x=k[c];
					k[c]=k[c+1];
					k[c+1]=x;
					x=g[c];
					g[c]=g[c+1];
					g[c+1]=x;
				}
			}
		}
		b=0;
		abcc();
	}
	return 0;
}