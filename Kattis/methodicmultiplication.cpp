#include<iostream>
using namespace std;

char s0[1048576], s1[1048576];

void print(int n)
{
    if (n == 0)
    {
        putchar('0');
        return;
    }
    printf("S(");
    print(n-1);
    putchar(')');
}

int main() {
    int i, a, b;
    while (scanf("%s%s", s0, s1) == 2)
    {
        for (i=0, a=0; s0[i]; i++)
        {
            if (s0[i] == 'S')
            {
                ++a;
            }
        }
        for (i=0, b=0; s1[i]; i++)
        {
            if (s1[i] == 'S')
            {
                ++b;
            }
        }
        print(a*b);
        puts("");
    }
    return 0;
}
