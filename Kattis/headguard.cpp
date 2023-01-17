#include <iostream>
using namespace std;

char buf[512];

int main()
{
	int i, j;
	while (fgets(buf, sizeof(buf), stdin))
	{
		for (i=0; buf[i]>=' '; i=j)
		{
			for (j=i+1; buf[j]>=' '&&buf[j]==buf[j-1]; j++);
			printf("%d%c", j-i, buf[i]);
		}
		puts("");
	}
	return 0;
}
