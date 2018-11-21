#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[35];
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		for(b=0,c=0;a>0;c++)
		{
			k[c]=a%2;
			b+=k[c];
			a/=2;
		}
		printf("The parity of ");
		for(c-=1;c>-1;c--)
		{
			printf("%d",k[c]);
		}
		printf(" is %d (mod 2).\n",b);
	}
	return 0;
}