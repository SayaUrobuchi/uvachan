#include<stdio.h>
int main()
{
	int b,c,d,e,f,g,h;
	unsigned long long a,i,j,k,l,m;
	char n[10],s;
	l=987654321;
	l*=10;
	l++;
	s=0;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		if(s)
		{
			printf("\n");
		}
		s=1;
		scanf("%llu",&i);
		for(a=1,j=i;j<l;a++,j+=i)
		{
			for(b=0;b<10;b++)
			{
				n[b]=0;
			}
			m=a;
			while(m>0)
			{
				b=m%10;
				if(n[b])
				{
					break;
				}
				n[b]=1;
				m/=10;
			}
			if(m)
			{
				continue;
			}
			for(b=0;b<10;b++)
			{
				n[b]=0;
			}
			m=j;
			while(m>0)
			{
				b=m%10;
				if(n[b])
				{
					break;
				}
				n[b]=1;
				m/=10;
			}
			if(!m)
			{
				printf("%llu / %llu = %llu\n",j,a,i);
			}
		}
	}
	return 0;
}