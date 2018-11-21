#include<stdio.h>
int main()
{
    char a[10000];
    int c=0,d;
    while(scanf("%c",&a[c])==1)
    {
        if(a[c]==32||a[c]==10)
        {
            for(d=c;d>0;d--)
            {
                printf("%c",a[d-1]);
            }
            printf("%c",a[c]);
            c=-1;
        }
        c++;
    }
    for(d=c;d>0;d--)
    {
        printf("%c",a[d-1]);
    }
    return 0;
}
