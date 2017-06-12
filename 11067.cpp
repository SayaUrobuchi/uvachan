#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j[101][101],x[10202][2];
char k[101][101];
int main()
{
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a==0&&b==0)
		{
			break;
		}
		a++;
		b++;
		for(c=0;c<a;c++)
		{
			for(d=0;d<b;d++)
			{
				j[c][d]=0;
				k[c][d]=0;
			}
		}
		a--;
		b--;
		scanf("%d",&h);
		for(e=1;h>0;h--)
		{
			scanf("%d%d",&c,&d);
			k[c][d]=1;
		}
		x[0][0]=a;
		x[0][1]=b;
		j[a][b]=1;
		for(e=0,f=1;e<f;e++)
		{
			c=x[e][0];
			d=x[e][1];
			if(c<a)
			{
				j[c][d]+=j[c+1][d];
			}
			if(d<b)
			{
				j[c][d]+=j[c][d+1];
			}
			if(c>0)
			{
				if(k[c-1][d]==0)
				{
					k[c-1][d]=1;
					x[f][0]=c-1;
					x[f][1]=d;
					f++;
				}
			}
			if(d>0)
			{
				if(k[c][d-1]==0)
				{
					k[c][d-1]=1;
					x[f][0]=c;
					x[f][1]=d-1;
					f++;
				}
			}
		}
		i=j[0][0];
		if(i==0)
		{
			printf("There is no path.\n");
		}
		else if(i==1)
		{
			printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
		}
		else
		{
			printf("There are %d paths from Little Red Riding Hood's house to her grandmother's house.\n",i);
		}
	}
	return 0;
}
