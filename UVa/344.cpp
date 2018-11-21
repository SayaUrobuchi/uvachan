#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[101][5];
	char x[5]={'i','v','x','l','c'};
	for(a=0;a<5;a++)
	{
		k[0][a]=0;
	}
	for(a=1;a<101;a++)
	{
		for(b=0;b<5;b++)
		{
			k[a][b]=k[a-1][b];
		}
		b=a/10;
		if(b<4)
		{
			k[a][2]+=b;
		}
		else if(b==4)
		{
			k[a][2]++;
			k[a][3]++;
		}
		else if(b<9)
		{
			k[a][2]+=b-5;
			k[a][3]++;
		}
		else
		{
			k[a][2]+=10-b;
			k[a][4]++;
		}
		b=a%10;
		if(b<4)
		{
			k[a][0]+=b;
		}
		else if(b==4)
		{
			k[a][0]++;
			k[a][1]++;
		}
		else if(b<9)
		{
			k[a][0]+=b-5;
			k[a][1]++;
		}
		else
		{
			k[a][0]+=10-b;
			k[a][2]++;
		}
	}
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		printf("%d:",a);
		for(b=0;b<4;b++)
		{
			printf(" %d %c,",k[a][b],x[b]);
		}
		printf(" %d %c\n",k[a][b],x[b]);
	}
	return 0;
}