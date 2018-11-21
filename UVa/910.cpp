#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j;
char k[26][2],l[30],m[30],y[2],z[2];
int abcc(int p,int q)
{
	if(q==a)
	{
		if(p==h)
		{
			return 1;
		}
		return 0;
	}
	return abcc(k[p][l[q]],q+1);
}
int abc(int p)
{
	int x;
	if(p==a)
	{
		return abcc(0,0);
	}
	l[p]=0;
	x=abc(p+1);
	l[p]=1;
	return x+abc(p+1);
}
int main()
{
	while(scanf("%d",&a)==1)
	{
		for(b=0;b<a;b++)
		{
			scanf("%s",&y);
			scanf("%s",&z);
			y[0]-=65;
			k[y[0]][0]=z[0]-65;
			scanf("%s",&z);
			k[y[0]][1]=z[0]-65;
			scanf("%s",&z);
			if(z[0]=='x')
			{
				h=y[0];
			}
		}
		scanf("%d",&a);
		i=abc(0);
		printf("%d\n",i);
	}
	return 0;
}