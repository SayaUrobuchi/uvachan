#include<stdio.h>
#include<math.h>
int a,b,c,d,e,f,g,h,i,j,k[78498][2],l[115];
int main()
{
	k[0][0]=2;
	k[0][1]=0;
	k[1][0]=3;
	k[1][1]=1;
	for(a=5,b=1;a<1000001;a+=2)
	{
		c=sqrt(a)+1;
		for(d=0;k[d][0]<c;d++)
		{
			if(!(a%k[d][0]))
			{
				break;
			}
		}
		if(k[d][0]>c-1)
		{
			k[++b][0]=a;
			k[b][1]=a-k[b-1][0];
		}
	}
	scanf("%d",&h);
	for(g=115;h>0;h--)
	{
		scanf("%d%d",&a,&b);
		i=0;
		j=78497;
		while(1)
		{
			c=i+j;
			c/=2;
			if(k[c][0]==a)
			{
				break;
			}
			else if(a>k[c][0])
			{
				i=c+1;
				if(i>j)
				{
					c++;
					break;
				}
			}
			else
			{
				j=c-1;
				if(i>j)
				{
					break;
				}
			}
		}
		i=0;
		j=78497;
		while(1)
		{
			d=i+j;
			d/=2;
			if(k[d][0]==b)
			{
				break;
			}
			else if(b>k[d][0])
			{
				i=d+1;
				if(i>j)
				{
					break;
				}
			}
			else
			{
				j=d-1;
				if(i>j)
				{
					d--;
					break;
				}
			}
		}
		if(c==d)
		{
			printf("No jumping champion\n");
			continue;
		}
		for(e=1;e<g;e++)
		{
			l[e]=0;
		}
		for(d++,e=c+1;e<d;e++)
		{
			l[k[e][1]]++;
		}
		for(e=1,i=0;e<115;e++)
		{
			if(l[e]>i)
			{
				i=l[e];
				f=e;
				j=0;
			}
			else if(l[e]==i)
			{
				j=1;
			}
		}
		if(j)
		{
			printf("No jumping champion\n");
		}
		else
		{
			printf("The jumping champion is %d\n",f);
		}
	}
	return 0;
}