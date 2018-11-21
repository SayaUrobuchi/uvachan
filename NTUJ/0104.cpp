#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h;
	long long i,j,k[51],l;
	k[0]=1;
	k[1]=2;
	i=1;
	j=1;
	for(a=2;a<51;a++)
	{
		k[a]=i*2+j;
		l=i;
		i+=j;
		j=l;
	}
	scanf("%d",&h);
	for(g=1,h++;g<h;g++)
	{
		scanf("%d",&a);
		printf("Scenario #%d:\n%lld\n\n",g,k[a]);
	}
	return 0;
}
