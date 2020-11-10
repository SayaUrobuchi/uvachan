#include<iostream>
using namespace std;

char s[1048576], t[1048576];

int main()
{
    int i, j;
    while (scanf("%s", s) == 1)
    {
        for (i=0, j=0; s[i]; i++)
        {
            if (s[i] == 'e')
            {
                t[j++] = s[i];
            }
            t[j++] = s[i];
        }
        t[j] = 0;
        puts(t);
    }
    return 0;
}

