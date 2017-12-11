/*
* 编程实现改进欧拉公式
*/

#include "iostream"
using namespace std;
#define N 18   // 等分数

// a, b : x 取值的上下界
// y0 ：x0 时的 y 取值
void ImprovedEuler(double *x, double *y, double a, double b, double y0, double(*f)(double, double))
{
	double h = (b - a) / N;
	double yp, yc;
	x[0] = a;
	y[0] = y0;
	for (int i = 0; i < N; i++)
	{
		x[i + 1] = x[i] + h;
		yp = y[i] + h * f(x[i], y[i]);
		yc = y[i] + h * f(x[i + 1], yp);
		y[i + 1] = 1.0 / 2.0 * (yp + yc);
	}
}

// 函数原型
double f(double x, double y)
{
	return -2 * x * y;
}

int main()
{
	double x[N + 1], y[N + 1];

	ImprovedEuler(x, y, 0, 1.8, 1, f);
	 
	printf("             改进欧拉公式\n");
	printf("************************************\n");

	for (int i = 0; i < N + 1; i++)
	{
		printf("x[%d] = %f, x[%d] = %f\n", i, x[i], i, y[i]);
	}
	printf("************************************\n");
	system("PAUSE");
	return 1;

}



