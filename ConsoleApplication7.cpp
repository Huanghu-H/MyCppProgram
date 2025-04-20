#include <stdio.h>
double P[92];
double p[92];
double EX=0;
int main()
{
	for (int i = 1; i <= 90; i++)
	{
		cout << i << endl;
		if (i <= 73)
		{
			P[i] = 0.006;
		}
		else if (i <= 89)
		{
			P[i] = 0.06 * (i - 73)+0.006;
		}
		else
		{
			P[i] = 1;
		}
		printf("%f\n", P[i]);
		//求每抽出金的概率

		p[i] = 1;
		for (int a = 1; a < i; a++)
		{
			p[i] = p[i] * (1 - P[a]);
			
		}
		
		p[i] = p[i] * P[i];
		printf("%f\n", p[i]);
		//求在n以前不出金，在第n抽出金的概率
		
	}

	EX = 0;
	for (int b = 1; b <= 90; b++)
	{
		EX = EX + b * p[b];
	}
	printf("\n\n\n%f\n", EX);
	//求出五星角色期望
	
	double e;
	e = EX * 1.5;
	printf("\n\n\n%f\n", e);
	//求出限定up五星角色期望

	return 0;
}
