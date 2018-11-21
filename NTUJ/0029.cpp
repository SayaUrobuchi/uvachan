#include <stdio.h>

char name[105], height[105], weight[105];

int main()
{
	int h, w;
	double bmi;
	while(scanf("%s%s%s", name, height, weight) == 3)
	{
		sscanf(height, "%d", &h);
		sscanf(weight, "%d", &w);
		bmi = w / (h/100.0) / (h/100.0);
		printf("%.2lf %s\n", bmi, bmi<18.5?"underweight":(bmi<=25.0?"normal":(bmi<=30.0?"overweight":"obese")));
	}
	return 0;
}
