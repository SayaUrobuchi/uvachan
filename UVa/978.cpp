#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[100001],l[100001],m[100001][2];
int abcc(int p,int q)
{
	int w,x;
	w=p/2;
	if(!w)
	{
		return 0;
	}
	if(q)
	{
		if(l[w]<l[p])
		{
			x=l[w];
			l[w]=l[p];
			l[p]=x;
			abcc(w,q);
		}
	}
	else
	{
		if(k[w]<k[p])
		{
			x=k[w];
			k[w]=k[p];
			k[p]=x;
			abcc(w,q);
		}
	}
	return 0;
}
int bcaa(int p,int q)
{
	int w,x;
	w=p*2;
	if(q)
	{
		if(w<f)
		{
			x=w;
			if(x+1<f)
			{
				if(l[x+1]>l[x])
				{
					x++;
				}
			}
			if(l[p]<l[x])
			{
				w=l[p];
				l[p]=l[x];
				l[x]=w;
				bcaa(x,q);
			}
		}
	}
	else
	{
		if(w<e)
		{
			x=w;
			if(x+1<e)
			{
				if(k[x+1]>k[x])
				{
					x++;
				}
			}
			if(k[p]<k[x])
			{
				w=k[p];
				k[p]=k[x];
				k[x]=w;
				bcaa(x,q);
			}
		}
	}
	return 0;
}
int main()
{
	char check;
	check = 0;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		if(check) printf("\n");
		check = 1;
		scanf("%d%d%d",&g,&e,&f);
		g++;
		for(a=1,e++;a<e;a++)
		{
			scanf("%d",&k[a]);
			abcc(a,0);
		}
		for(a=1,f++;a<f;a++)
		{
			scanf("%d",&l[a]);
			abcc(a,1);
		}
		while(e>1&&f>1)
		{
			if(g>e)
			{
				g=e;
			}
			if(g>f)
			{
				g=f;
			}
			for(a=1;a<g;a++)
			{
				m[a][0]=k[1];
				e--;
				k[1]=k[e];
				bcaa(1,0);
				m[a][1]=l[1];
				f--;
				l[1]=l[f];
				bcaa(1,1);
			}
			for(a=1;a<g;a++)
			{
				if(m[a][0]>m[a][1])
				{
					k[e]=m[a][0]-m[a][1];
					abcc(e,0);
					e++;
				}
				else if(m[a][1]>m[a][0])
				{
					l[f]=m[a][1]-m[a][0];
					abcc(f,1);
					f++;
				}
			}
		}
		if(e==1)
		{
			if(f==1)
			{
				printf("green and blue died\n");
			}
			else
			{
				printf("blue wins\n");
				for(a=1;f>1;a++)
				{
					printf("%d\n",l[1]);
					l[1]=l[--f];
					bcaa(1,1);
				}
			}
		}
		else
		{
			printf("green wins\n");
			for(a=1;e>1;a++)
			{
				printf("%d\n",k[1]);
				k[1]=k[--e];
				bcaa(1,0);
			}
		}
	}
	return 0;
}
