#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g[1000],h;
	char i[75],j[1000][75],k[75],x;
	scanf("%d%c",&h,&x);
	a=0;
	for(h;h>0;h--)
	{
		scanf("%s",&i);
		gets(k);
		for(b=0;b<a;b++)
		{
			if(j[b][0]==i[0])
			{
				if(strcmp(j[b],i)==0)
				{
					g[b]++;
					break;
				}
			}
		}
		if(b==a)
		{
			strcpy(j[a],i);
			g[a]=1;
			a++;
		}
	}
	a--;
	for(b=0,d=a;b<a;b++,d--)
	{
		for(c=0,e=0;c<d;c++)
		{
			for(f=0;j[c][f]!='\0'&&j[c+1][f]!='\0';f++)
			{
				if(j[c][f]>j[c+1][f])
				{
					strcpy(i,j[c]);
					strcpy(j[c],j[c+1]);
					strcpy(j[c+1],i);
					f=g[c];
					g[c]=g[c+1];
					g[c+1]=f;
					e++;
					break;
				}
				else if(j[c][f]<j[c+1][f])
				{
					break;
				}
			}
		}
		if(e==0)
		{
			break;
		}
	}
	for(b=0;b<=a;b++)
	{
		printf("%s %d\n",j[b],g[b]);
	}
	return 0;
}