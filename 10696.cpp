#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k;
int abcc(int b)
{
    if(b>100)
    {
        return b-10;
    }
    else
    {
        return abcc(abcc(b+11));
    }
}
int main()
{
    while(scanf("%d",&a)==1)
    {
        if(a==0)
        {
            break;
        }
        c=abcc(a);
        printf("f91(%d) = %d\n",a,c);
    }
    return 0;
}
