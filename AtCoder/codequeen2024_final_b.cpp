#include <iostream>
using namespace std;

const string KEY[] = {
	"-----", ".----", "..---", "...--", "....-", 
	".....", "-....", "--...", "---..", "----."
};

char buf[16];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	string ans;
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		for (j=0; j<=9; j++)
		{
			if (KEY[j] == buf)
			{
				ans += j + '0';
			}
		}
	}
	puts(ans.c_str());
	return 0;
}