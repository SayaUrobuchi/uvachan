#include<stdio.h>
#include<math.h>
int a,b,c,d,e,f,g,h,i,j[200][2],k[200][200],l[200];
int abcc(int p,int q)
{
	int w,x;
	if(q==1)
	{
		if(p<l[q])
		{
			l[q]=p;
		}
		return p;
	}
	for(w=0;w<a;w++)
	{
		if(w!=q)
		{
			x=p;
			if(k[q][w]>x)
			{
				x=k[q][w];
			}
			if(x<l[w])
			{
				l[w]=x;
				x=abcc(x,w);
				if(x<l[q])
				{
					l[q]=x;
				}
			}
		}
	}
	return l[q];
}
int main()
{
	int s;
	s=0;
	h=0;
	while(scanf("%d",&a)==1)
	{
		if(s)
		{
			printf("\n");
		}
		s=1;
		if(a==0)
		{
			break;
		}
		for(b=0;b<a;b++)
		{
			l[b]=2000001;
			scanf("%d%d",&j[b][0],&j[b][1]);
			for(c=0;c<b;c++)
			{
				d=j[c][0]-j[b][0];
				d*=d;
				e=j[c][1]-j[b][1];
				e*=e;
				k[b][c]=d+e;
				k[c][b]=k[b][c];
			}
		}
		l[0]=0;
		abcc(0,0);
		printf("Scenario #%d\n",++h);
		printf("Frog Distance = %.3f\n",sqrt(l[1]));
	}
	return 0;
}