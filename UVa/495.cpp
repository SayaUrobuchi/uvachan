#include<stdio.h>
#include<string.h>
char k[5001][1200];
int i[5001];
int abcc(int b)
{
	int a,p,q,x,y;
	p=b-2;
	q=b-1;
	x=i[p];
	y=i[q];
	for(a=0;a<x;a++)
	{
		k[b][a]=k[p][a]+k[q][a];
	}
	for(a;a<y;a++)
	{
		k[b][a]=k[q][a];
	}
	k[b][a]=0;
	for(a=0;a<y;a++)
	{
		if(k[b][a]>9)
		{
			k[b][a+1]+=k[b][a]/10;
			k[b][a]%=10;
		}
	}
	i[b]=y;
	if(k[b][a]>0)
	{
		i[b]++;
	}
	return 0;
}
int main()
{
	int a,b,c;
	k[0][0]=0;
	i[0]=1;
	i[1]=1;
	k[1][0]=1;
	i[2]=1;
	k[2][0]=1;
	for(a=3;a<5001;a++)
	{
		abcc(a);
	}
	while(scanf("%d",&a)==1)
	{
		printf("The Fibonacci number for %d is ",a);
		for(b=i[a]-1;b>=0;b--)
		{
			printf("%d",k[a][b]);
		}
		printf("\n");
	}
	return 0;
}