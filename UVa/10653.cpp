#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[1000][1000],l[1000000][3];
int main()
{
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a&&!b)
		{
			break;
		}
		for(c=0;c<a;c++)
		{
			for(d=0;d<b;d++)
			{
				k[c][d]=1;
			}
		}
		scanf("%d",&h);
		for(h;h>0;h--)
		{
			scanf("%d%d",&c,&g);
			for(g;g>0;g--)
			{
				scanf("%d",&d);
				k[c][d]=0;
			}
		}
		scanf("%d%d%d%d",&c,&d,&e,&f);
		l[0][0]=c;
		l[0][1]=d;
		l[0][2]=0;
		k[c][d]=0;
		for(c=0,d=1;c<d;c++)
		{
			i=l[c][0];
			j=l[c][1];
			h=l[c][2]+1;
			if(i>0)
			{
				if(k[i-1][j])
				{
					if(i-1==e&&j==f)
					{
						break;
					}
					l[d][0]=i-1;
					l[d][1]=j;
					l[d++][2]=h;
					k[i-1][j]=0;
				}
			}
			if(j>0)
			{
				if(k[i][j-1])
				{
					if(i==e&&j-1==f)
					{
						break;
					}
					l[d][0]=i;
					l[d][1]=j-1;
					l[d++][2]=h;
					k[i][j-1]=0;
				}
			}
			if(i<a-1)
			{
				if(k[i+1][j])
				{
					if(i+1==e&&j==f)
					{
						break;
					}
					l[d][0]=i+1;
					l[d][1]=j;
					l[d++][2]=h;
					k[i+1][j]=0;
				}
			}
			if(j<b-1)
			{
				if(k[i][j+1])
				{
					if(i==e&&j+1==f)
					{
						break;
					}
					l[d][0]=i;
					l[d][1]=j+1;
					l[d++][2]=h;
					k[i][j+1]=0;
				}
			}
		}
		printf("%d\n",h);
	}
	return 0;
}