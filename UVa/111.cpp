#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h[21],i[21],j,k[21],x;
    scanf("%d",&x);
    i[0]=-1;
    for(a=1;a<=x;a++)
    {
        scanf("%d",&j);
        k[j]=a;
    }
    a=1;
    while(scanf("%d",&j)==1)
    {
        h[j]=a;
        for(a=2;a<=x;a++)
        {
            scanf("%d",&j);
            h[j]=a;
        }
        for(a=1,c=1;a<=x;a++)
        {
            for(b=1;b<=x;b++)
            {
                if(h[a]==k[b])
                {
                    break;
                }
            }
            if(b>i[c-1])
            {
                i[c]=b;
                c++;
            }
            else
            {
                for(d=c-2;d>=0;d--)
                {
                    if(b>i[d])
                    {
                        i[d+1]=b;
                        break;
                    }
                }
            }
        }
        printf("%d\n",c-1);
        a=1;
    }
    return 0;
}
