#include<stdio.h>
#include<string.h>
int a,b,c,d,e,f,g,h,i,j;
char k[4][5];
int abcc(int m,int n)
{
	int p,q,r,s,w,x,y,z[16][2];
	y=0;
	for(p=m;p<a;p++)
	{
		for(q=0;q<a;q++)
		{
			if(p==m&&q<n)
			{
				continue;
			}
			if(k[p][q]=='.')
			{
				k[p][q]='Y';
				w=0;
				for(r=p+1,s=q;r<a;r++)
				{
					if(k[r][s]=='X')
					{
						break;
					}
					else if(k[r][s]=='.')
					{
						k[r][s]='Y';
						z[w][0]=r;
						z[w++][1]=s;
					}
				}
				for(r=p,s=q+1;s<a;s++)
				{
					if(k[r][s]=='X')
					{
						break;
					}
					else if(k[r][s]=='.')
					{
						k[r][s]='Y';
						z[w][0]=r;
						z[w++][1]=s;
					}
				}
				for(r=p-1,s=q;r>-1;r--)
				{
					if(k[r][s]=='X')
					{
						break;
					}
					else if(k[r][s]=='.')
					{
						k[r][s]='Y';
						z[w][0]=r;
						z[w++][1]=s;
					}
				}
				for(r=p,s=q-1;s>-1;s--)
				{
					if(k[r][s]=='X')
					{
						break;
					}
					else if(k[r][s]=='.')
					{
						k[r][s]='Y';
						z[w][0]=r;
						z[w++][1]=s;
					}
				}
				j++;
				x=abcc(p,q+1);
				j--;
				if(x>y)
				{
					y=x;
				}
				for(x=0;x<w;x++)
				{
					k[z[x][0]][z[x][1]]='.';
				}
				k[p][q]='.';
			}
		}
	}
	if(!y)
	{
		return j;
	}
	return y;
}
int main()
{
	while(scanf("%d",&a)==1)
	{
		if(!a)
		{
			break;
		}
		gets(k[0]);
		for(b=0;b<a;b++)
		{
			gets(k[b]);
		}
		j=0;
		i=abcc(0,0);
		printf("%d\n",i);
	}
	return 0;
}