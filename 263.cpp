#include<stdio.h>
#include<stdlib.h>
int abcc(const void *p,const void *q)
{
	return *(char*)p-*(char*)q;
}
int main()
{
	int a,b,c,d,e,f,g,h,i,j,l[1001];
	char k[10];
	while(scanf("%d",&a)==1)
	{
		if(!a)
		{
			break;
		}
		printf("Original number was %d\n",a);
		for(b=0;;b++)
		{
			if(!a)
			{
				printf("0 - 0 = 0\n");
				b++;
				break;
			}
			for(c=a,d=0;c>0;c/=10,d++)
			{
				k[d]=c%10;
			}
			qsort(k,d,sizeof(char),abcc);
			for(i=0,e=0;e<d;e++)
			{
				i*=10;
				i+=k[e];
			}
			for(j=0,e=d-1;e>-1;e--)
			{
				j*=10;
				j+=k[e];
			}
			d=j-i;
			printf("%d - %d = %d\n",j,i,d);
			for(c=0;c<b;c++)
			{
				if(l[c]==d)
				{
					break;
				}
			}
			if(c<b)
			{
				b++;
				break;
			}
			l[b]=d;
			a=d;
		}
		printf("Chain length %d\n\n",b);
	}
	return 0;
}