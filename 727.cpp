#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	char k[2],l[51],m[51],n[51], check;
	scanf("%d",&h);
	gets(k);
	gets(k);
	check = 0;
	for(h;h>0;h--)
	{
		if(check) printf("\n");
		check = 1;
		a=0;
		b=-1;
		while(gets(k))
		{
			if(!k[0])
			{
				break;
			}
			if(k[0]=='+'||k[0]=='-')
			{
				c=1;
			}
			else if(k[0]=='*'||k[0]=='/')
			{
				c=2;
			}
			else if(k[0]=='(')
			{
				c=0;
			}
			else if(k[0]==')')
			{
				c=3;
			}
			else
			{
				c=5;
			}
			if(c==3)
			{
				for(b;b>-1;b--)
				{
					if(l[b]=='(')
					{
						b--;
						break;
					}
					n[a++]=l[b];
				}
			}
			else
			{
				if(c)
				{
					for(b;b>-1;b--)
					{
						if(m[b]<c)
						{
							break;
						}
						else
						{
							n[a++]=l[b];
						}
					}
				}
				l[++b]=k[0];
				m[b]=c;
			}
		}
		for(b;b>-1;b--)
		{
			n[a++]=l[b];
		}
		n[a]=0;
		printf("%s\n",n);
	}
	return 0;
}
