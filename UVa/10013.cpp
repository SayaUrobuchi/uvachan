#include<stdio.h>
int a,b,c,d,e,f,g,h,i[1000000],j[1000000],k;
char check;
int main()
{
	check = 0;
	scanf("%d",&k);
	for(k;k>0;k--)
	{
		if(check) printf("\n");
		check = 1;
		scanf("%d",&a);
		for(b=0;b<a;b++)
		{
			scanf("%d %d",&i[b],&j[b]);
		}
		b--;
		for(b;b>0;b--)
		{
			i[b]+=j[b];
			if(i[b]>9)
			{
				i[b-1]++;
				i[b]-=10;
			}
		}
		i[0]+=j[0];
		for(b=0;b<a;b++)
		{
			printf("%d",i[b]);
		}
		printf("\n");
	}
	return 0;
}
