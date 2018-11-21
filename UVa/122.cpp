#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	int i,m;
	char j[260];
}abc;
int abcc(const void *p,const void *q)
{
	return strcmp((*(abc*)p).j,(*(abc*)q).j);
}
int aabc(const void *p,const void *q)
{
	int y,z;
	y=(*(abc*)p).m;
	z=(*(abc*)q).m;
	if(y==z)
	{
		return strcmp((*(abc*)p).j,(*(abc*)q).j);
	}
	return y-z;
}
int a,b,c,d,e,f,g,h;
abc k[257];
char x;
int bcaa(int p)
{
	if(b==a)
	{
		return 0;
	}
	int q,w;
	char y[260];
	q=k[b].m;
	strcpy(y,k[b-1].j);
	if(q>p)
	{
		return -1;
	}
	if(strcmp(k[b].j,y)==0)
	{
		return -1;
	}
	if(q==p)
	{
		if(strncmp(k[b].j,y,p-1)!=0)
		{
			return -1;
		}
		b++;
		w=bcaa(p+1);
		if(w==-1)
		{
			return -1;
		}
		if(b==a)
		{
			return 0;
		}
		q=strlen(k[b].j);
		if(q==p)
		{
			if(strncmp(k[b].j,y,p-1)!=0)
			{
				return -1;
			}
			b++;
			w=bcaa(p+1);
			if(w==-1)
			{
				return -1;
			}
		}
	}
	return 0;
}
int main()
{
	a=0;
	while(scanf("%c",&x)==1)
	{
		if(x=='(')
		{
			b=0;
			k[a].i=0;
			while(scanf("%c",&x)==1)
			{
				if(x>47&&x<58)
				{
					k[a].i*=10;
					k[a].i+=x-48;
				}
				else if(x==')')
				{
					break;
				}
				else if(x!=',')
				{
					k[a].j[b++]=x;
				}
			}
			if(k[a].i!=0)
			{
				k[a].j[b]='\0';
				k[a].m=b;
				a++;
			}
			else
			{
				qsort(k,a,sizeof(abc),abcc);
				if(strcmp(k[0].j,"")==0)
				{
					b=1;
					c=bcaa(1);
					if(c==-1)
					{
						printf("not complete\n");
					}
					else
					{
						qsort(k,a,sizeof(abc),aabc);
						printf("%d",k[0].i);
						for(b=1;b<a;b++)
						{
							printf(" %d",k[b].i);
						}
						printf("\n");
					}
				}
				else
				{
					printf("not complete\n");
				}
				a=0;
			}
		}
	}
	return 0;
}