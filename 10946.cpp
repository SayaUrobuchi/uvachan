#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int i;
	char j;
}abc;
int abcc(const void *r,const void *s)
{
	if((*(abc*)r).i==(*(abc*)s).i)
	{
		return (*(abc*)r).j-(*(abc*)s).j;
	}
	else
	{
		return (*(abc*)s).i-(*(abc*)r).i;
	}
}
int main()
{
	int a,b,c,d,e,f,g,h,z[2500][2],p,q;
	abc k[2500];
	char x,y[50][51];
	q=0;
	while(scanf("%d%d%c",&a,&b,&x)==3)
	{
		if(a==0&&b==0)
		{
			break;
		}
		for(c=0;c<a;c++)
		{
			gets(y[c]);
		}
		for(c=0,h=0;c<a;c++)
		{
			for(d=0;d<b;d++)
			{
				if(y[c][d]!='.')
				{
					x=y[c][d];
					k[h].j=x;
					y[c][d]='.';
					z[0][0]=c;
					z[0][1]=d;
					g=1;
					for(p=0;p<g;p++)
					{
						e=z[p][0];
						f=z[p][1];
						if(e>0)
						{
							if(y[e-1][f]==x)
							{
								y[e-1][f]='.';
								z[g][0]=e-1;
								z[g][1]=f;
								g++;
							}
						}
						if(e<a-1)
						{
							if(y[e+1][f]==x)
							{
								y[e+1][f]='.';
								z[g][0]=e+1;
								z[g][1]=f;
								g++;
							}
						}
						if(f>0)
						{
							if(y[e][f-1]==x)
							{
								y[e][f-1]='.';
								z[g][0]=e;
								z[g][1]=f-1;
								g++;
							}
						}
						if(f<b-1)
						{
							if(y[e][f+1]==x)
							{
								y[e][f+1]='.';
								z[g][0]=e;
								z[g][1]=f+1;
								g++;
							}
						}
					}
					k[h].i=g;
					h++;
				}
			}
		}
		qsort(k,h,sizeof(abc),abcc);
		printf("Problem %d:\n",++q);
		for(a=0;a<h;a++)
		{
			printf("%c %d\n",k[a].j,k[a].i);
		}
	}
	return 0;
}