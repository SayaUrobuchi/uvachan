#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[1000];
	while(scanf("%d %d %d",&h,&i,&j)==3)
	{
		if(h==0)
		{
			if(i==j&&j==0)
			{
				break;
			}
		}
		for(a=1;a<=h;a++)
		{
			k[a]=1;
		}
		a=1;
		b=h;
		g=h;
		e=0;
		while(g>0)
		{
			c=0;
			for(;;a++)
			{
				if(a==h+1)
				{
					a=1;
				}
				c+=k[a];
				if(c==i)
				{
					c=a;
					g--;
					a++;
					break;
				}
			}
			d=0;
			for(;;b--)
			{
				if(b==0)
				{
					b=h;
				}
				d+=k[b];
				if(d==j)
				{
					d=b;
					if(e==1)
					{
						printf(",");
					}
					e=1;
					if(d!=c)
					{
						g--;
						k[d]=0;
						printf("%3d%3d",c,d);
					}
					else
					{
						printf("%3d",c);
					}
					k[c]=0;
					b--;
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}