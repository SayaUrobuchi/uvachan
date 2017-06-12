#include<stdio.h>
#include<math.h>
#include<string.h>
bool x[20000001];
int a,b,c,d,e,f,g,h,i,j[2000],k[100001][2];
int main()
{
	for(a=0;a<20000001;a++)
	{
		x[a]=0;
	}
	//memset(x,0,sizeof(int)*20000001);
	j[0]=2;
	for(a=3,b=0,e=0;a<=4473;a+=2)
	{
		d=j[0]*j[0];
		for(c=0;d<=a;c++,d=j[c]*j[c])
		{
			if(a%j[c]==0)
			{
				break;
			}
		}
		if(d>a)
		{
			j[e]=a;
			e++;
		}
	}
	for(a=0;a<e;a++)
	{
		d=j[a]*2;
		for(b=j[a]*3;b<20000001;b+=d)
		{
			x[b]=1;
		}
	}
	for(a=3,b=1;b<100001;a+=2)
	{
		if(x[a]==0&&x[a+2]==0)
		{
			k[b][0]=a;
			k[b][1]=a+2;
			b++;
		}
	}
	while(scanf("%d",&a)==1)
	{
		printf("(%d, %d)\n",k[a][0],k[a][1]);
	}
	return 0;
}