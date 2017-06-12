#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[92][8],l[8],m[8];
int abcc()
{
	int p,q,w,x;
	if(a==8)
	{
		for(b=0;b<8;b++)
		{
			k[i][b]=l[b];
		}
		i++;
		return 0;
	}
	for(w=0;w<8;w++)
	{
		if(m[w])
		{
			for(p=w-1,q=a-1;p>-1&&q>-1;p--,q--)
			{
				if(l[q]==p)
				{
					break;
				}
			}
			if(p>-1&&q>-1)
			{
				continue;
			}
			for(p=w+1,q=a-1;p<8&&q>-1;p++,q--)
			{
				if(l[q]==p)
				{
					break;
				}
			}
			if(p==8||q==-1)
			{
				m[w]=0;
				l[a]=w;
				a++;
				abcc();
				a--;
				m[w]=1;
			}
		}
	}
	return 0;
}
int main()
{
	for(a=0;a<8;a++)
	{
		m[a]=1;
	}
	a=0;
	i=0;
	abcc();
	h=0;
	while(scanf("%d",&l[0])==1)
	{
		l[0]--;
		for(b=1;b<8;b++)
		{
			scanf("%d",&l[b]);
			l[b]--;
		}
		for(b=0,i=0;b<92;b++)
		{
			j=0;
			for(c=0;c<8;c++)
			{
				if(k[b][c]==l[c])
				{
					j++;
				}
			}
			if(j>i)
			{
				i=j;
			}
		}
		printf("Case %d: %d\n",++h,8-i);
	}
	return 0;
}