#include<stdio.h>
#include<string.h>
int a,b,c,d,e,f,g,h,i,j;
char k[1050];
bool l[5],m[5];
int abcc()
{
	int w,x;
	if(k[a]>111&&k[a]<117)
	{
		return l[k[a]-112];
	}
	else if(k[a]=='N')
	{
		a++;
		x=abcc();
		return (x+1)%2;
	}
	else if(k[a]=='K')
	{
		a++;
		w=abcc();
		a++;
		x=abcc();
		return w&x;
	}
	else if(k[a]=='A')
	{
		a++;
		w=abcc();
		a++;
		x=abcc();
		return w|x;
	}
	else if(k[a]=='C')
	{
		a++;
		w=abcc();
		a++;
		x=abcc();
		if(w&&!x)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		a++;
		w=abcc();
		a++;
		x=abcc();
		return !(w^x);
	}
}
int abc(int p)
{
	int w;
	if(p==5)
	{
		a=0;
		w=abcc();
		if(!w)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if(m[p])
	{
		l[p]=0;
		w=abc(p+1);
		if(!w)
		{
			return 0;
		}
		l[p]=1;
		w=abc(p+1);
		if(!w)
		{
			return 0;
		}
	}
	else
	{
		w=abc(p+1);
		if(!w)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	while(gets(k))
	{
		if(!strcmp(k,"0"))
		{
			break;
		}
		for(a=0,b=strlen(k);a<5;a++)
		{
			m[a]=0;
		}
		for(a=0;a<b;a++)
		{
			if(k[a]>111||k[a]<117)
			{
				m[k[a]-112]=1;
			}
		}
		c=abc(0);
		if(c)
		{
			printf("tautology\n");
		}
		else
		{
			printf("not\n");
		}
	}
	return 0;
}