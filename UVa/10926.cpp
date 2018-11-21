#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[100][101];
bool l[100][100],m[100];
int abcc(int p)
{
	int q,w,x;
	for(w=1;w<k[p][0];w++)
	{
		l[p][k[p][w]]=1;
		if(!m[k[p][w]])
		{
			for(x=0;x<a;x++)
			{
				l[k[p][w]][x]=0;
			}
			abcc(k[p][w]);
			m[k[p][w]]=1;
		}
		for(x=0;x<a;x++)
		{
			if(l[k[p][w]][x])
			{
				l[p][x]=1;
			}
		}
	}
	return 0;
}
int main()
{
	while(scanf("%d",&a)==1)
	{
		if(!a)
		{
			break;
		}
		for(b=0;b<a;b++)
		{
			m[b]=0;
			scanf("%d",&c);
			k[b][0]=1;
			for(d=0;d<c;d++)
			{
				scanf("%d",&k[b][k[b][0]]);
				k[b][k[b][0]++]--;
			}
		}
		i=-1;
		for(b=0;b<a;b++)
		{
			if(!m[b])
			{
				for(c=0;c<a;c++)
				{
					l[b][c]=0;
				}
				abcc(b);
				m[b]=1;
			}
			for(c=0,d=0;d<a;d++)
			{
				c+=l[b][d];
			}
			if(c>i)
			{
				i=c;
				j=b+1;
			}
		}
		printf("%d\n",j);
	}
	return 0;
}