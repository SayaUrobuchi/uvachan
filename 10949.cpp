#include<stdio.h>
int a,b,c,d,e,f,g,h,m,n,p,r,s,j[95][1400],k[20001],y,z;
int main()
{
	char i[20001],x[21][21],q;
	scanf("%d",&y);
	for(z=1;z<=y;z++)
	{
		scanf("%d %d%c",&a,&b,&q);
		for(c=1;c<=a;c++)
		{
			gets(x[c]);
		}
		for(c=0;c<95;c++)
		{
			j[c][0]=0;
		}
		scanf("%d %d %d%c",&a,&b,&c,&q);
		gets(i);
		d=a;
		c--;
		q=x[b][c];
		q-=33;
		j[q][1]=1;
		j[q][0]=1;
		for(e=0;e<d;e++)
		{
			q=i[e];
			if(q=='N')
			{
				b--;
			}
			else if(q=='E')
			{
				c++;
			}
			else if(q=='S')
			{
				b++;
			}
			else
			{
				c--;
			}
			q=x[b][c];
			q-=33;
			j[q][0]++;
			h=j[q][0];
			j[q][h]=e+2;
		}
		//----------------------
		scanf("%d %d %d%c",&a,&b,&c,&q);
		gets(i);
		f=a;
		c--;
		q=x[b][c];
		q-=33;
		p=0;
		if(j[q][0]!=0)
		{
			k[1]=j[q][1];
			p=1;
		}
		for(e=0;e<f;e++)
		{
			q=i[e];
			if(q=='N')
			{
				b--;
			}
			else if(q=='E')
			{
				c++;
			}
			else if(q=='S')
			{
				b++;
			}
			else
			{
				c--;
			}
			q=x[b][c];
			q-=33;
			h=j[q][0];
			if(h==0)
			{
				continue;
			}
			m=h;
			for(r=p;r>0;r--)
			{
				if(j[q][m]>k[r])
				{
					if(r==p)
					{
						p++;
					}
					r++;
					k[r]=j[q][m];
					m--;
					if(m==0)
					{
						break;
					}
				}
			}
			if(p==0)
			{
				p=1;
			}
			if(r==0)
			{
				k[1]=j[q][1];
			}
		}
		d-=p;
		d++;
		f-=p;
		f++;
		printf("Case %d: %d %d\n",z,d,f);
	}
	return 0;
}
