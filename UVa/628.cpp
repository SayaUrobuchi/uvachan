#include<stdio.h>
#include<string.h>
char k[100][257],x[100],y[5000];
int a,b,c,d,e,f,g,h,i,j;
int abcc(int p,int q)
{
	if(p==e)
	{
		printf("%s\n",y);
		return 0;
	}
	if(x[p]=='#')
	{
		strcat(y,k[d]);
		abcc(p+1,q+c);
		y[q]='\0';
	}
	else
	{
		int r;
		strcat(y,"0");
		for(r=0;r<10;r++)
		{
			abcc(p+1,q+1);
			y[q]++;
		}
		y[q]='\0';
	}
	return 0;
}
int main()
{
	while(scanf("%d",&h)==1)
	{
		gets(x);
		for(a=0;a<h;a++)
		{
			gets(k[a]);
		}
		printf("--\n");
		scanf("%d",&h);
		gets(x);
		for(h;h>0;h--)
		{
			gets(x);
			e=strlen(x);
			for(d=0;d<a;d++)
			{
				c=strlen(k[d]);
				abcc(0,0);
			}
		}
	}
	return 0;
}