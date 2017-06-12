#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[10], l;
	char x[81];
	char *ptr;
	while(gets(x))
	{
		a=strlen(x);
		ptr = x;
		while(*ptr == 32) ptr++;
		l = a;
		while(x[--l] == 32);
		x[++l] = 0;
		for(b=0,c=0,d=0,e=0;x[b];b++)
		{
			if(x[b]>47&&x[b]<58)
			{
				if(c<10)
				{
					k[c++]=x[b]-48;
				}
				else
				{
					d=1;
				}
			}
			else if(x[b]=='X')
			{
				if(c==9)
				{
					k[c++]=10;
				}
				else
				{
					d=1;
				}
			}
			else if(x[b]!=32&&x[b]!='-')
			{
				d=1;
			}
		}
		if(c!=10)
		{
			d=1;
		}
		if(d==1)
		{
			printf("%s is incorrect.\n",ptr);
		}
		else
		{
			for(a=1;a<10;a++)
			{
				k[a]+=k[a-1];
			}
			for(a=0,b=0;a<10;a++)
			{
				b+=k[a];
			}
			if(b%11==0)
			{
				printf("%s is correct.\n",ptr);
			}
			else
			{
				printf("%s is incorrect.\n",ptr);
			}
		}
	}
	return 0;
}
