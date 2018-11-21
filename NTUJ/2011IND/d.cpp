#include <stdio.h>
#include <string.h>
#include <map>
#include <string>

using namespace std;

int k1, k2, kf1, kf2, bi, bi1, bi2;
char *buf, buf1[1000000], buf2[1000000], kn1[100000], kn2[100000];

int is_alp(int c)
{
	return c>='a' && c<='z';
}

int main()
{
	int count;
	int t;
	char *p, *q;
	char c;
	scanf("%d", &count);
	while(count--)
	{
		map<string, int> m;
		buf = buf1;
		bi = 0;
		while(scanf("%c", &c) == 1)
		{
			buf[bi++] = c;
			if(c == '-')
			{
				break;
			}
		}
		buf[bi] = 0;
		bi1 = bi;
		buf = buf2;
		bi = 0;
		while(scanf("%c", &c) == 1)
		{
			buf[bi++] = c;
			if(c == '-')
			{
				break;
			}
		}
		buf[bi] = 0;
		bi2 = bi;
		p = buf1;
		q = buf2;
		k1 = 0;
		k2 = 0;
		t = 40;
		while(*p||*q)
		{
			kf1 = 0;
			while(*p&&!is_alp(*p))
			{
				kf1 = k1;
				p++;
			}
			if(kf1)
			{
				kn1[k1] = 0;
			}
			kf2 = 0;
			while(*q&&!is_alp(*q))
			{
				kf2 = k2;
				q++;
			}
			if(kf2)
			{
				kn2[k2] = 0;
			}
			if(kf1 && !m[kn1])
			{
				if(kf2 && !m[kn2])
				{
					if(strcmp(kn1, kn2) == 0)
					{
					}
					else if(strcmp(kn1, kn2) > 0)
					{
						m[kn2] = 1;
						m[kn1] = 1;
						printf("%s %d\n", kn2, t);
						printf("%s %d\n", kn1, t);
					}
					else
					{
						m[kn2] = 1;
						m[kn1] = 1;
						printf("%s %d\n", kn1, t);
						printf("%s %d\n", kn2, t);
					}
				}
				else
				{
					m[kn1] = 1;
					printf("%s %d\n", kn1, t);
				}
			}
			else if(kf2 && !m[kn2])
			{
				m[kn2] = 1;
				printf("%s %d\n", kn2, t);
			}
			if(kf1)
			{
				k1 = 0;
			}
			if(kf2)
			{
				k2 = 0;
			}
			if(is_alp(*p))
			{
				kn1[k1++] = *p++;
			}
			if(is_alp(*q))
			{
				kn2[k2++] = *q++;
			}
			t++;
		}
		printf("-\n");
	}
	return 0;
}
