#include<stdio.h>
int main()
{
	int o;
	int a,b,c,d,e,f,g,h,w,x;
	double i,j,k,l,p,q;
	scanf("%d",&o);
	printf("INTERSECTING LINES OUTPUT\n");
	for(o;o>0;o--)
	{
		scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
		w=c-a;
		x=g-e;
		if(w==0)
		{
			if(x==0)
			{
				if(a==e)
				{
					printf("LINE\n");
				}
				else
				{
					printf("NONE\n");
				}
			}
			else
			{
				i=h;
				i-=f;
				i/=x;
				k=f;
				k-=i*e;
				j=i*a+k;
				i=a;
				printf("POINT %.2f %.2f\n",i,j);
			}
		}
		else if(x==0)
		{
			i=d;
			i-=b;
			i/=w;
			k=b;
			k-=i*a;
			j=i*e+k;
			i=e;
			printf("POINT %.2f %.2f\n",i,j);
		}
		else
		{
			i=d;
			i-=b;
			j=h;
			j-=f;
			i/=w;
			j/=x;
			k=b;
			k-=i*a;
			l=f;
			l-=j*e;
			p=i-j;
			q=k-l;
			if(p>-0.00001&&p<0.00001)
			{
				if(q>-0.00001&&q<0.00001)
				{
					printf("LINE\n");
				}
				else
				{
					printf("NONE\n");
				}
			}
			else
			{
				p=l-k;
				p/=i-j;
				q=i*p+k;
				printf("POINT %.2f %.2f\n",p,q);
			}
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}