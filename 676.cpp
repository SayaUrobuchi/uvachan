#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[10][10],l[50001][2];
int abcc(int p,int q)
{
	int w;
	if(e>=50000)
	{
		printf("more than 50000 steps\n");
		return 1;
	}
	if(p==c&&q==d)
	{
		for(w=0;w<e;w++)
		{
			printf("(%d,%d), ",l[w][0],l[w][1]);
		}
		printf("(%d,%d)\n",p,q);
		return 1;
	}
	l[e][0]=p;
	l[e++][1]=q;
	k[p][q]=0;
	if(q<9&&p>1)
	{
		if(k[p-1][q+1])
		{
			w=abcc(p-1,q+1);
			if(w)
			{
				return 1;
			}
			l[e][0]=p;
			l[e++][1]=q;
		}
	}
	if(q<9&&p<9)
	{
		if(k[p+1][q+1])
		{
			w=abcc(p+1,q+1);
			if(w)
			{
				return 1;
			}
			l[e][0]=p;
			l[e++][1]=q;
		}
	}
	if(q>1&&p<9)
	{
		if(k[p+1][q-1])
		{
			w=abcc(p+1,q-1);
			if(w)
			{
				return 1;
			}
			l[e][0]=p;
			l[e++][1]=q;
		}
	}
	if(q>1&&p>1)
	{
		if(k[p-1][q-1])
		{
			w=abcc(p-1,q-1);
			if(w)
			{
				return 1;
			}
			l[e][0]=p;
			l[e++][1]=q;
		}
	}
	k[p][q]=1;
	return 0;
}
int main()
{
	char y[2],s;
	s=0;
	scanf("%d",&h);
	gets(y);
	for(h;h>0;h--)
	{
		if(s)
		{
			printf("\n");
		}
		s=1;
		gets(y);
		scanf("%c%d",&y[0],&a);
		scanf("%c%d",&y[0],&b);
		gets(y);
		scanf("%c%d",&y[0],&c);
		scanf("%c%d",&y[0],&d);
		gets(y);
		e=c+d-a-b;
		if(e%2)
		{
			printf("fail\n");
		}
		else
		{
			for(e=1;e<10;e++)
			{
				for(f=1;f<10;f++)
				{
					k[e][f]=1;
				}
			}
			e=0;
			abcc(a,b);
		}
	}
	return 0;
}