#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,l[8];
bool k[1000001];
int abcc(int p,int q)
{
	if(p==b)
	{
		if(q<1000001)
		{
			k[q]=0;
		}
		return 0;
	}
	int w,x;
	for(w=0;w<10;w++)
	{
		abcc(p+1,q+w*l[p]);
	}
	return 0;
}
int main()
{
	for(a=1;a<1000001;a++)
	{
		k[a]=1;
	}
	for(a=2,b=0;a<1000000;a=a*10-9,b++)
	{
		l[b]=a;
	}
	abcc(0,0);
	for(a=1;a<1000001;a++)
	{
		if(k[a])
		{
			printf("%d\n",a);
		}
	}
	return 0;
}