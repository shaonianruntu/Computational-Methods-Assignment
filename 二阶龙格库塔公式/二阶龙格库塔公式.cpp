/*
 * 编程实现二阶龙格-库塔公式
 */

#include "iostream"
using namespace std;
#define N 18   // 等分数

// a, b : x 取值的上下界
// y0 ：x0 时的 y 取值
void RungeKutta(double *x,  double *y, double a, double b, double y0, double(*f)(double, double))
{
	double h = (b - a) / N;
	double k1, k2;
	x[0] = a;
	y[0] = y0;
	for (int i = 0; i < N; i++)
	{
		x[i + 1] = x[i] + h;
		k1 = f(x[i], y[i]);
		k2 = f(x[i] + h / 2, y[i] + h / 2 * k1);
		y[i + 1] = y[i] + h*k2;
	}
}

// 函数原型
double f(double x, double y)
{
	return -2 * x*y;
}

int main()
{
	double x[N+1], y[N+1];

	RungeKutta(x, y, 0, 1.8, 1, f);

	printf("          二阶龙格库塔公式\n");
	printf("************************************\n");

	for (int i = 0; i < N+1; i++)
	{
		printf("x[%d] = %f, x[%d] = %f\n", i, x[i], i, y[i]);
	}
	printf("************************************\n");
	system("PAUSE");
	return 1;

}



