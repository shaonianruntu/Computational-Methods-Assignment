/*
 * ���ʵ�� n ��ţ�ٲ�ֵ����ʽ 
 */

#include "iostream"
#include "cmath"
using namespace std;

#define N 3

//�����Ľṹ
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
	// �����鱾P97���⣬����50��Ӧ�����0.76543��
	printf("���������ţ�ٲ�ֵ����ʽ��xֵ��");
	double xx;
	scanf("%lf", &xx);

	int n = N - 1;

	// ���̼���
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

	// n ��ţ�ٲ�ֵ��ʽ
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

