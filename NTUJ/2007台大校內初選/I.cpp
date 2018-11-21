#include <stdio.h>
#include <string.h>

int main()
{
	int cm, kg;
	char buf[101], cmstr[101], kgstr[101];
	double bmi;
	while(scanf("%s%s%s", buf, cmstr, kgstr) == 3)
	{
		sscanf(cmstr, "%d", &cm);
		sscanf(kgstr, "%d", &kg);
		bmi = 1.0 * kg / ((cm / 100.0) * (cm / 100.0));
		if(bmi < 18.5)
		{
			printf("%.2f underweight\n", bmi);
		}
		else if(bmi > 30.0)
		{
			printf("%.2f obese\n", bmi);
		}
		else if(bmi > 25.0)
		{
			printf("%.2f overweight\n", bmi);
		}
		else
		{
			printf("%.2f normal\n", bmi);
		}
	}
	return 0;
}
