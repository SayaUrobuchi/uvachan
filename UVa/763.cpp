#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	char k[120],x[120],y,z[120];
	for(a=0;a<119;a++)
	{
		x[a]=0;
		z[a]=48;
	}
	x[a]=0;
	z[a]='\0';
	strcpy(k,z);
	gets(k);
	gets(x);
	a=strlen(k);
	b=strlen(x);
	for(c=0,d=a-1;c<d;c++,d--)
	{
		y=k[c];
		k[c]=k[d];
		k[d]=y;
	}
	k[a]=48;
	for(c=0,d=b-1;c<d;c++,d--)
	{
		y=x[c];
		x[c]=x[d];
		x[d]=y;
	}
	for(c=0;c<b;c++)
	{
		x[c]-=48;
	}
	x[b]=0;
	if(a<b)
	{
		a=b;
	}
	for(c=0;c<a;c++)
	{
		k[c]+=x[c];
	}
	for(c=a-1;;c--)
	{
		if(c==0)
		{
			if(k[c]>49)
			{
				k[c]-=2;
				k[++c]++;
				c++;
				c++;
			}
			else
			{
				break;
			}
		}
		if(k[c]>49)
		{
			k[c]-=2;
			if(c==1)
			{
				k[c-1]++;
				k[++c]++;
				c++;
				c++;
			}
			else
			{
				k[c-2]++;
				k[++c]++;
				c++;
				c++;
			}
		}
		else if(k[c]==49)
		{
			if(k[c-1]>48)
			{
				k[c]--;
				k[c-1]--;
				k[++c]++;
				c++;
				c++;
			}
		}
	}
	for(c=a+3;c>0;c--)
	{
		if(k[c]!=48)
		{
			break;
		}
	}
	for(c;c>=0;c--)
	{
		printf("%c",k[c]);
	}
	printf("\n");
	while(scanf("%c",&y)==1)
	{
		strcpy(k,z);
		for(c=0;c<120;c++)
		{
			x[c]=0;
		}
		gets(k);
		gets(x);
		a=strlen(k);
		b=strlen(x);
		for(c=0,d=a-1;c<d;c++,d--)
		{
			y=k[c];
			k[c]=k[d];
			k[d]=y;
		}
		k[a]=48;
		for(c=0,d=b-1;c<d;c++,d--)
		{
			y=x[c];
			x[c]=x[d];
			x[d]=y;
		}
		for(c=0;c<b;c++)
		{
			x[c]-=48;
		}
		x[b]=0;
		if(a<b)
		{
			a=b;
		}
		for(c=0;c<a;c++)
		{
			k[c]+=x[c];
		}
		for(c=a-1;;c--)
		{
			if(c==0)
			{
				if(k[c]>49)
				{
					k[c]-=2;
					k[++c]++;
					c++;
					c++;
				}
				else
				{
					break;
				}
			}
			if(k[c]>49)
			{
				k[c]-=2;
				if(c==1)
				{
					k[c-1]++;
					k[++c]++;
					c++;
					c++;
				}
				else
				{
					k[c-2]++;
					k[++c]++;
					c++;
					c++;
				}
			}
			else if(k[c]==49)
			{
				if(k[c-1]>48)
				{
					k[c]--;
					k[c-1]--;
					k[++c]++;
					c++;
					c++;
				}
			}
		}
		for(c=a+3;c>0;c--)
		{
			if(k[c]!=48)
			{
				break;
			}
		}
		printf("\n");
		for(c;c>=0;c--)
		{
			printf("%c",k[c]);
		}
		printf("\n");
	}
	return 0;
}
