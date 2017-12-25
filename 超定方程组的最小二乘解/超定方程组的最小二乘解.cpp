/*
 *  ���ʵ�ֳ������������С���˽�
 */

#include "iostream"
#include "iomanip"
#include "cmath"
using namespace std;

#define m 5
#define n 2

void fun(double A[n][n], double b[n], double X[n]);

int main() {
	// ������
	double A[m][n] = {
		{2, -1},
		{8, 4},
		{2, 1},
		{7, -1},
		{4, 0}
	};
	double b[m] = {
		1,
		0,
		1,
		8,
		3
	};

	double ATA[n][n];
	double ATb[n];
	double x[n];

	// ATA �� ATb �ĳ�ʼ��
	for (int i = 0; i < n; i++) {
		ATb[i] = 0;
		for (int j = 0; j < n; j++) {
			ATA[i][j] = 0;
		}
	}
	// ���� ATA
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				ATA[i][j] += A[k][i] * A[k][j];
			}
		}
	}
	// ���� ATb
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ATb[i] += A[j][i] * b[j];
		}
	}

	cout << "ATA[" << n << "][" << n << "] = " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(15) << ATA[i][j];
		}
		cout << endl;
	}
	cout << "ATb[" << n << "] = " << endl;
	for (int i = 0; i < n; i++) {
			cout << setw(15) << ATb[i] << endl;
	}
	cout << endl;

	// ʹ������Ԫ��˹��ȥ�������Է�����
	fun(ATA, ATb, x);
	cout << "���������С���˽⣺" << endl;
	cout << "x = " << x[0] << ", " << x[1] << endl << endl;

	system("PAUSE");


}

// ʹ������Ԫ��˹��ȥ��������Է�����
void fun(double A[n][n], double b[n], double X[n]) {
	double tmp;
	int label1;
	int label2;

	double mm[n]; // �����е���Ԫ��������
	double x[n];  // ���̵Ľ�



	for (int j = 0; j < n; j++) {
		tmp = A[j][j];  // 
		for (int i = j; i < n; i++) {
			if (fabs(A[i][j]) > tmp) {
				tmp = A[i][j];
				label1 = i;
				label2 = j;
			}
		}
		if (tmp == 0)
		{
			cout << "ʧ��" << endl;
			break; 
		}
		// ������
		if (label1 != label2) {    
			for (int k = j; k < n; k++) {
				tmp = A[label1][k];
				A[label1][k] = A[label2][k];
				A[label2][k] = tmp;
			}
			tmp = b[label1];
			b[label1] = b[label2];
			b[label2] = tmp;
		}
		// ��Ԫ
		for (int k = j + 1; k < n; k++) {  
			mm[k] = A[k][j] / A[j][j];
			for (int w = j; w < n; w++) {
				A[k][w] -= mm[k] * A[j][w];
			}
			b[k] -= mm[k] * b[j];
		}
	}
	tmp = 0.0;
	x[n - 1] = b[n - 1] / A[n - 1][n - 1];
	for (int i = (n - 1) - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			tmp += A[i][j] * x[j];
		}
		x[i] = (b[i] - tmp) / A[i][i];
		tmp = 0.0;
	}
	for (int i = 0; i < n; i++) {
		X[i] = x[i];
	}
}