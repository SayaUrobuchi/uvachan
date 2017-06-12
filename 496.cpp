#include<stdio.h>
    int a[10000],b[10000],c=0,d,e,g,h,i,j,k;
int main()
{
    char f;
    while(scanf("%d%c",&a[c],&f)==2)
    {
        if(f==10)
        {
            c++;
            for(d=0;d>=0;d++)
            {
                scanf("%d%c",&b[d],&f);
                if(f==10)
                {
                    d++;
                    break;
                }
            }
            for(g=1;g<c;g++)
            {
                for(h=1,i=0;h<c;h++)
                {
                    if(a[h]<a[h-1])
                    {
                        e=a[h];
                        a[h]=a[h-1];
                        a[h-1]=e;
                        i++;
                    }
                }
                if(i==0)
                {
                    break;
                }
            }
            for(g=1;g<d;g++)
            {
                for(h=1,i=0;h<d;h++)
                {
                    if(b[h]<b[h-1])
                    {
                        e=b[h];
                        b[h]=b[h-1];
                        b[h-1]=e;
                        i++;
                    }
                }
                if(i==0)
                {
                    break;
                }
            }
            if(c<d)
            {
               for(g=0,i=0,j=0;g<c;g++)
                {
                    if(g>d||i>=d)
                    {
                        break;
                    }
                    for(h=i;h<d;h++)
                    {
                        if(a[g]==b[h])
                        {
                            j++;
                        }
                        else if(a[g]<b[h])
                        {
                            i=h;
                            break;
                        }
                        i=h;
                    }
                } 
            }
            else
            {
                for(g=0,i=0,j=0;g<d;g++)
                {
                    if(g>c||i>=c)
                    {
                        break;
                    }
                    for(h=i;h<c;h++)
                    {
                        if(a[h]==b[g])
                        {
                            j++;
                            i=h;
                            break;
                        }
                        else if(a[h]>b[g])
                        {
                            i=h;
                            break;
                        }
                        i=h;
                    }
                }
            }
            if(j==c&&j==d)
            {
                printf("A equals B\n");
            }
            else if(j==c)
            {
                printf("A is a proper subset of B\n");
            }
            else if(j==d)
            {
                printf("B is a proper subset of A\n");
            }
            else if(j==0)
            {
                printf("A and B are disjoint\n");
            }
            else
            {
                printf("I'm confused!\n");
            }
            c=-1;
        }
        c++;
    }
    return 0;
}
