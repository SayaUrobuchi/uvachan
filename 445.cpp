#include<stdio.h>
int main()
{
    char a,b;
    int c=0,d,e,f,g,h,i,j,k,s,t;
	s=0;
	t=0;
    while(scanf("%c",&a)==1)
    {
        if(a>47&&a<58)
        {
            a-=48;
            c+=a;
        }
        else if(a=='!'||a==10)
        {
            printf("\n");
        }
        else if(a=='b')
        {
            for(c;c>0;c--)
            {
                printf("%c",32);
            }
        }
        else
        {
            for(c;c>0;c--)
            {
                printf("%c",a);
            }
        }
    }
    return 0;
}
