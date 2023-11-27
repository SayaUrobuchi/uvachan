#include <iostream>
using namespace std;

char s[128];

int main()
{
	int n, i, j, k;
	fgets(s, sizeof(s), stdin);
	for (i=0, n=0; s[i]; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[n++] = s[i];
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[n++] = (s[i] ^ 32);
		}
	}
	bool pal;
	for (k=2, pal=false; !pal&&k<=3; k++)
	{
		for (i=0, j=i+k-1; !pal&&j<n; i++, j++)
		{
			if (s[i] == s[j])
			{
				pal = true;
			}
		}
	}
	puts(pal?"Palindrome":"Anti-palindrome");
	return 0;
}
