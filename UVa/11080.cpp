#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[200][200],l[200];
int abcc(int p,int q,int y)
{
    int w,x;
    j++;
    if(q==1)
    {
        i++;
    }
    q*=-1;
    for(w=1;w<k[p][0];w++)
    {
		if(k[p][w]==y)
		{
			continue;
		}
        if(!l[k[p][w]])
        {
            l[k[p][w]]=q;
            x=abcc(k[p][w],q,p);
			if(x)
			{
				return 1;
			}
        }
        else if(l[k[p][w]]==l[p])
        {
            return 1;
        }
	}
    return 0;
}
int main()
{
    scanf("%d",&h);
    for(h;h>0;h--)
    {
        scanf("%d%d",&a,&b);
        for(c=0;c<a;c++)
        {
            k[c][0]=1;
            l[c]=0;
        }
        for(b;b>0;b--)
		{
            scanf("%d%d",&c,&d);
            k[c][k[c][0]++]=d;
            k[d][k[d][0]++]=c;
        }
        for(b=0,g=0;b<a;b++)
        {
            if(!l[b])
            {
                i=0;
                j=0;
                l[b]=-1;
                c=abcc(b,-1,b);
                if(c)
                {
                    break;
                }
                if(i<j-i)
                {
                    if(!i)
                    {
                        g+=j-i;
					}
                    else
                    {
                        g+=i;
                    }
                }
                else
                {
                    if(!(j-i))
                    {
                        g+=i;
                    }
                    else
                    {
                        g+=j-i;
                    }
                }
            }
        }
        if(c)
        {
            printf("-1\n");
		}
        else
        {
            printf("%d\n",g);
        }
    }
    return 0;
}