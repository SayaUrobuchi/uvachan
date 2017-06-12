#include<stdio.h>
#include<string.h>
int a,b,c,d,e,f,g,h,i,j[200][2],k[123][2];
char x,y[200];
int abcc()
{
	if(d==a)
	{
		return 0;
	}
	int q,w,z[2][2];
	q=0;
	for(d;d<a;d++)
	{
		if(y[d]=='(')
		{
			d++;
			w=abcc();
			if(w==-1)
			{
				return -1;
			}
			z[q][0]=j[w][0];
			z[q][1]=j[w][1];
			if(q==0)
			{
				q++;
			}
			else
			{
				if(z[0][1]!=z[1][0])
				{
					return -1;
				}
				else
				{
					c+=z[0][0]*z[0][1]*z[1][1];
					z[0][1]=z[1][1];
				}
			}
		}
		else if(y[d]==')')
		{
			j[b][0]=z[0][0];
			j[b][1]=z[0][1];
			return b++;
		}
		else
		{
			z[q][0]=k[y[d]][0];
			z[q][1]=k[y[d]][1];
			if(q==0)
			{
				q++;
			}
			else
			{
				if(z[0][1]!=z[1][0])
				{
					return -1;
				}
				else
				{
					c+=z[0][0]*z[0][1]*z[1][1];
					z[0][1]=z[1][1];
				}
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&h);
	gets(y);
	for(h;h>0;h--)
	{
		scanf("%c",&x);
		scanf("%d%d",&k[x][0],&k[x][1]);
		gets(y);
	}
	while(gets(y))
	{
		a=strlen(y);
		b=0;
		c=0;
		d=0;
		e=abcc();
		if(e==-1)
		{
			printf("error\n");
		}
		else
		{
			printf("%d\n",c);
		}
	}
	return 0;
}