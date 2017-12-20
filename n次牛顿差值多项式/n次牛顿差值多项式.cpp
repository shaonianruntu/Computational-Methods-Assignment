/*
 * 编程实现 n 次牛顿插值多项式 
 */

#include "iostream"
#include "cmath"
using namespace std;

#define N 3

//输入点的结构
struct Data
{
	double x;
	double y;
} d[N] = {
	{ 30.0, 1.0 / 2.0 },
	{ 45.0, sqrt(2) / 2.0 },
	{ 60.0, sqrt(3) / 2.0 }
};

int main() {
	// 根据书本P97例题，输入50，应该输出0.76543。
	printf("请输入计算牛顿差值多项式的x值：");
	double xx;
	scanf("%lf", &xx);

	int n = N - 1;

	// 差商计算
	double f[N];

	for (int k = 1; k <= n; k++) {
		double temp = 1.0;
		double sum = 0.0;

		for (int m = 0; m <= k; m++) {
			for (int i = 0; i <= k; i++) {
				if (i != m) {
					temp *= (d[m].x - d[i].x);
				}
			}
			sum += d[m].y / temp;
			temp = 1.0;
		}
		f[k] = sum;
		sum = 0;
	}

	// n 次牛顿差值公式
	double newton = d[0].y;
	double tmp = 1.0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			tmp *= (xx - d[j].x);
		}
		newton += f[i] * tmp;
		tmp = 1.0;
	}

	printf("N%d(x) = %lf\n", n, newton);
	system("PAUSE");
	return 0;
}

