#include<stdio.h>
#include<math.h>
int a,b,c,d,e,f,g,h,i,j[750][2],k[750][750],l[750],m[750];
bool n[750];
double x;
int abcc(int p)
{
	int q;
	l[p]=-1;
	for(q=0;q<a;q++)
	{
		if(l[q]!=-1)
		{
			d=j[q][0]-j[p][0];
			d*=d;
			d+=(j[q][1]-j[p][1])*(j[q][1]-j[p][1]);
			if(d<l[q]||!l[q])
			{
				l[q]=d;
				m[q]=p;
			}
		}
	}
	for(q=1;q<k[p][0];q++)
	{
		if(l[k[p][q]]!=-1)
		{
			abcc(k[p][q]);
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
		for(b=0;b<a;b++)
		{
			scanf("%d%d",&j[b][0],&j[b][1]);
			k[b][0]=1;
			l[b]=0;
			m[b]=0;
			n[b]=0;
		}
		scanf("%d",&g);
		for(i=a,x=0;g>0;g--)
		{
			scanf("%d%d",&b,&c);
			b--;
			c--;
			k[b][k[b][0]++]=c;
			k[c][k[c][0]++]=b;
			n[b]=1;
			n[c]=1;
		}	
		for(b=0;b<a;b++)
		{
			if(n[b])
			{
				abcc(b);
				break;
			}
		}
		if(b==a)
		{
			abcc(0);
		}
		i=0;
		while(1)
		{
			for(b=0,c=0,d=0,e=0;b<a;b++)
			{
				if(l[b]!=-1)
				{
					if(l[b]<c||!c)
					{
						c=l[b];
						d=b;
					}
				}
				else
				{
					e++;
				}
			}
			if(e==a)
			{
				break;
			}
			printf("%d %d\n",d+1,m[d]+1);
			abcc(d);
			i++;
		}
		if(i==0)
		{
			printf("No new highways need\n");
			continue;
		}
	}
	return 0;
}
