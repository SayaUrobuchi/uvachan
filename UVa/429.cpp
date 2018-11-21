#include<stdio.h>
#include<string.h>
typedef struct
{
	int i,p[201];
	char k[11];
}abc;
int a,b,c,d,e,f,g,h,q[40001],r[40001];
char x,y[25],z[11],t;
bool s[200];
abc j[200];
int main()
{
	t=0;
	scanf("%d%c",&h,&x);
	scanf("%c",&x);
	for(h;h>0;h--)
	{
		if(t)
		{
			printf("\n");
		}
		t=1;
		a=0;
		while(gets(j[a].k))
		{
			if(strcmp(j[a].k,"*")==0)
			{
				break;
			}
			j[a].i=strlen(j[a].k);
			j[a].p[0]=1;
			for(b=0,c=j[a].i;b<a;b++)
			{
				if(c==j[b].i)
				{
					for(d=0,e=0;d<c;d++)
					{
						if(j[b].k[d]==j[a].k[d])
						{
							e++;
						}
					}
					if(e==c-1)
					{
						j[a].p[j[a].p[0]]=b;
						j[a].p[0]++;
						j[b].p[j[b].p[0]]=a;
						j[b].p[0]++;
					}
				}
			}
			a++;
		}
		while(gets(y))
		{
			for(a=0;a<200;a++)
			{
				s[a]=0;
			}
			b=strlen(y);
			if(b==0)
			{
				break;
			}
			b/=2;
			y[b]='\0';
			for(c=b+1,d=0;d<=b;c++,d++)
			{
				z[d]=y[c];
			}
			for(c=0;c<a;c++)
			{
				if(b==j[c].i)
				{
					if(strcmp(y,j[c].k)==0)
					{
						break;
					}
				}
			}
			s[c]=1;
			q[0]=c;
			r[0]=0;
			d=1;
			for(e=0;e<d;e++)
			{
				f=q[e];
				if(strcmp(z,j[f].k)==0)
				{
					printf("%s %s %d\n",y,z,r[e]);
					break;
				}
				for(g=1;g<j[f].p[0];g++)
				{
					if(s[j[f].p[g]]==0)
					{
						q[d]=j[f].p[g];
						r[d]=r[e]+1;
						s[q[d]]=1;
						d++;
					}
				}
			}
		}
	}
	return 0;
}