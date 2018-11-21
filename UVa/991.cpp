#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[11],l;
	char check;
	check = 0;
	k[1]=1;
	for(a=2;a<11;a++)
	{
		k[a]=k[a-1]*(4*a-2)/(a+1);
	}
	while(scanf("%d",&a)==1)
	{
		if(check) printf("\n");
		check = 1;
		printf("%d\n",k[a]);
	}
	return 0;
}
