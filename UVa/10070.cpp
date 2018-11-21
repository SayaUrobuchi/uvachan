#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e;
	char k[1500],x, check;
	bool p,q,r,s,t,u;
	check = 0;
	while(scanf("%s",&k)==1)
	{
		if(check) printf("\n");
		check = 1;
		p=0;
		q=0;
		r=0;
		s=0;
		t=0;
		u=0;
		a=strlen(k);
		for(b=0,c=0,d=0,e=1;b<a;b++)
		{
			c+=k[b];
			d+=k[b]*e;
			e*=-1;
		}
		b=0;
		if(e==-1)
		{
			d-=48;
		}
		if(c%3==0)
		{
			p=1;
		}
		if(d%11==0)
		{
			q=1;
		}
		if((k[--a]-48)%5==0)
		{
			r=1;
		}
		if((k[a]+k[a-1]*10)%4==0)
		{
			s=1;
		}
		if(k[a]+k[a-1]==96)
		{
			t=1;
			if((k[a-2]+k[a-3]*10)%4==0)
			{
				u=1;
			}
		}
		if(u==1)
		{
			printf("This is leap year.\n");
			b=100;
		}
		else if(s==1&&t==0)
		{
			printf("This is leap year.\n");
			b=100;
		}
		if(p==1&&r==1)
		{
			printf("This is huluculu festival year.\n");
			b++;
		}
		if(r==1&&q==1)
		{
			if(b>99)
			{
				printf("This is bulukulu festival year.\n");
				b++;
			}
		}
		if(b==0)
		{
			printf("This is an ordinary year.\n");
		}
	}
	return 0;
}
