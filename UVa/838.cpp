#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[12][12];
bool l[1001];
int abcc(int p,int q)
{
	if(j==d)
	{
		i=j;
		d=0;
		return 0;
	}
	if(j>i)
	{
		i=j;
	}
	if(p>0)
	{
		if(l[k[p-1][q]])
		{
			l[k[p-1][q]]=0;
			j++;
			abcc(p-1,q);
			if(!d)
			{
				return 0;
			}
			j--;
			l[k[p-1][q]]=1;
		}
	}
	if(q<a-1)
	{
		if(l[k[p][q+1]])
		{
			l[k[p][q+1]]=0;
			j++;
			abcc(p,q+1);
			if(!d)
			{
				return 0;
			}
			j--;
			l[k[p][q+1]]=1;
		}
	}
	if(p<a-1)
	{
		if(l[k[p+1][q]])
		{
			l[k[p+1][q]]=0;
			j++;
			abcc(p+1,q);
			if(!d)
			{
				return 0;
			}
			j--;
			l[k[p+1][q]]=1;
		}
	}
	if(q>0)
	{
		if(l[k[p][q-1]])
		{
			l[k[p][q-1]]=0;
			j++;
			abcc(p,q-1);
			if(!d)
			{
				return 0;
			}
			j--;
			l[k[p][q-1]]=1;
		}
	}
	return 0;
}
int main()
{
	char check;
	check = 0;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		if(check) printf("\n");
		check = 1;
		scanf("%d",&a);
		for(b=0;b<1001;b++)
		{
			l[b]=1;
		}
		for(b=0,d=0;b<a;b++)
		{
			for(c=0;c<a;c++)
			{
				scanf("%d",&k[b][c]);
				d+=l[k[b][c]];
				l[k[b][c]]=0;
			}
		}
		for(b=0;b<1001;b++)
		{
			l[b]=1;
		}
		for(b=0,i=0;b<a;b++)
		{
			for(c=0;c<a;c++)
			{
				j=1;
				l[k[b][c]]=0;
				abcc(b,c);
				if(!d)
				{
					break;
				}
				l[k[b][c]]=1;
			}
			if(!d)
			{
				break;
			}
		}
		printf("%d\n",i);
	}
	return 0;
}
