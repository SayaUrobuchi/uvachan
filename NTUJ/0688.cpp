#include <stdio.h>
unsigned short int n[10055],m[100130050];
int main()
{
    n[0]=1;
    n[1]=2;
    int a,b,c;
    for(a=2;a<=10050;a++)
    {
        n[a]=((n[a-1]+n[a-2])<<1);
        n[a]%=10007;
    }
    m[0]=1;
    m[1]=4;
    for(a=2, c=a;a<=100130050;a++, c++)
    {
        if(c == 10006)
        {
			c = 0;
		}
        m[a]=(((m[a-1]+m[a-2])<<1)+n[c])%10007;
    }
    while(scanf("%d",&a)==1)
    {
        if(a==-1)
        {
            break;
        }
        a%=100130042;
        printf("%d\n",m[a]);
    }
    return 0;
}
