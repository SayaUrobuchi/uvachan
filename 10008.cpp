#include<stdio.h>
int main()
{
    int a[26][2],c,d,e,f,g,h;
    char b;
    while(scanf("%d",&c)==1)
    {
        scanf("%c",&b);
        for(d=0;d<26;d++)
        {
            a[d][0]=d+65;
            a[d][1]=0;
        }
        for(c;c>0;c--)
        {
            scanf("%c",&b);
            if(b!=10)
            {
                c++;
                if(b>64&&b<91)
                {
                    a[b-65][1]++;
                }
                else if(b>96&&b<123)
                {
                    a[b-97][1]++;
                }
            }
        }
        for(c=0;c<25;c++)
        {
            for(d=0;d<25;d++)
            {
                if(a[d][1]<a[d+1][1])
                {
                    e=a[d][1];
                    a[d][1]=a[d+1][1];
                    a[d+1][1]=e;
                    e=a[d][0];
                    a[d][0]=a[d+1][0];
                    a[d+1][0]=e;
                }
            }
        }
        for(c=0;c<26;c++)
        {
            if(a[c][1]==0)
            {
                break;
            }
            printf("%c %d\n",a[c][0],a[c][1]);
        }
    }
    return 0;
}
