/*
 * 编写追赶法的程序
 */

#include<stdio.h>
#define N 4
void main()
{
	int i;
	float a[N], b[N], c[N], d[N], u[N], l[N - 1];
	float x[N], y[N];
	printf("请输入系数矩阵：\n");
	for (i = 0; i<N; i++)
	{
		scanf("%f", &a[i]);  
		scanf("%f", &b[i]);
		scanf("%f", &c[i]);
		scanf("%f", &d[i]);
	}
	u[0] = b[0];
	for (i = 1; i<N; i++)
	{
		l[i - 1] = a[i - 1] / u[i - 1];
		u[i] = b[i] - l[i - 1] * c[i - 1];
	}
	y[0] = d[0];
	for (i = 1; i<N; i++)
	{
		y[i] = d[i] - l[i - 1] * y[i - 1];
	}
	x[N - 1] = y[N - 1] / u[N - 1];
	for (i = N - 2; i >= 0; i--)
		x[i] = (y[i] - c[i] * x[i + 1]) / u[i];
	for (i = 0; i<N; i++)
		printf("x%d=%f\n", i + 1, x[i]);
}
