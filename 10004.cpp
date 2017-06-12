#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i[200],j,k[200][101];
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		scanf("%d",&b);
		for(c=0;c<a;c++)
		{
			k[c][0]=1;
			i[c]=0;
		}
		for(b;b>0;b--)
		{
			scanf("%d %d",&c,&d);
			if(c>d)
			{
				e=c;
				c=d;
				d=e;
			}
			j=k[c][0];
			k[c][j]=d;
			k[c][0]++;
		}
		i[0]=1;
		for(c=0,h=0;c<a;c++)
		{
			j=k[c][0];
			if(j>1)
			{
				d=i[c]*-1;
				for(f=1;f<j;f++)
				{
					e=k[c][f];
					if(i[e]==0)
					{
						i[e]=d;
					}
					else if(i[e]!=d)
					{
						h=1;
						break;
					}
				}
				if(h==1)
				{
					break;
				}
			}
		}
		if(h==1)
		{
			printf("NOT BICOLORABLE.\n");
		}
		else
		{
			printf("BICOLORABLE.\n");
		}
	}
	return 0;
}