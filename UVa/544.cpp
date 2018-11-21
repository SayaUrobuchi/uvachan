#include<stdio.h>
#include<string.h>
int a,b,c,d,e,f,g,h,i,j,k[200][200],l[200];
char x[200][31],y[31],z[31];
/*int abcc(int p,int w)
{
    if(w==d)
    {
        return l[w];
    }
    int q,m,n;
    for(q=0,m=10001;q<200;q++)
    {
        if(k[w][q]!=0)
        {
			n=k[w][q];
			if(p<n)
			{
				n=p;
			}
            if(n>l[q])
            {
                l[q]=n;
                n=abcc(n,q);
                if(n<m)
                {
                    m=n;
                }
            }
        }
    }
    if(l[w]<m)
    {
        return l[w];
    }
    else
    {
		l[w]=m;
        return m;
    }
}*/
int abcc(int p,int q)
{
	int m,n,w;
	if(q==c)
	{
		if(p>l[q])
		{
			l[q]=p;
		}
		return p;
	}
	for(w=0,m=-1;w<i;w++)
	{
		if(k[q][w])
		{
			n=p;
			if(k[q][w]<n)
			{
				n=k[q][w];
			}
			if(n>l[w])
			{
				l[w]=n;
				n=abcc(n,w);
				if(n>m)
				{
					m=n;
				}
			}
		}
	}
	if(m<l[q]&&m!=-1)
	{
		l[q]=m;
	}
	return m;
}
int main()
{
    a=0;
    h=0;
    while(scanf("%d%d",&b,&c)==2)
    {
        if(a==0&&b==0)
        {
            break;
        }
        for(d=0;d<b;d++)
        {
            l[d]=0;
            for(e=0;e<b;e++)
            {
                k[d][e]=0;
            }
        }
        for(d=0,i=0;d<c;d++)
        {
            scanf("%s%s%d",y,z,&e);
            for(j=0;j<i;j++)
            {
                if(strcmp(x[j],y)==0)
                {
                    break;
                }
            }
            f=j;
            if(f==i)
            {
                strcpy(x[i++],y);
            }
            for(j=0;j<i;j++)
            {
                if(strcmp(x[j],z)==0)
                {
                    break;
                }
            }
            if(j==i)
            {
                strcpy(x[i++],z);
            }
            k[f][j]=e;
            k[j][f]=e;
        }
        scanf("%s%s",&y,&z);
        for(c=0;c<i;c++)
        {
            if(strcmp(x[c],y)==0)
            {
                break;
            }
        }
        for(d=0;d<i;d++)
        {
            if(strcmp(x[d],z)==0)
            {
                break;
            }
        }
        /*l[c]=10001;
        e=abcc(10001,c);*/
		e=abcc(10001,d);
		//printf("%d tons\n\n",l[d]);
        printf("Scenario #%d\n",++h);
		printf("%d tons\n\n",l[c]);
    }
    return 0;
}
