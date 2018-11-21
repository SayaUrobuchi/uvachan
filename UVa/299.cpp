#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[51];
	scanf("%d",&g);
	for(g;g>0;g--)
	{
		scanf("%d",&a);
		for(b=0;b<a;b++)
		{
			scanf("%d",&k[b]);
		}
		a--;
		for(b=0,j=0;b<a;b++)
		{
			i=0;
			e=a-b;
			for(c=0;c<e;c++)
			{
				if(k[c]>k[c+1])
				{
					d=k[c];
					k[c]=k[c+1];
					k[c+1]=d;
					i++;
				}
			}
			if(i==0)
			{
				break;
			}
			j+=i;
		}
		printf("Optimal train swapping takes %d swaps.\n",j);
	}
	return 0;
}