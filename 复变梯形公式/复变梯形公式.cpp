#include "iostream"
using namespace std;

float f1(float x) {
	float y;
	y = 1 / (1 + x);
	return y;
}

float f2(float x) {
	float y;
	y = x * x;
	return y;
}

float f3(float x) {
	float y;
	y = 1 + x;
	return y;
}

float func(float x, int fun) {
	switch (fun) {
	case 1: return f1(x);
	case 2: return f2(x);
	case 3: return f3(x);
	default: printf("��ĺ���ѡ����������������!"); return -1;
	}
};

int main() {
	printf("   �������ι�ʽʵ��\n");
	printf("************************\n\n");

	int fun;
	printf("����������Ҫ����ĺ�����\n");
	printf("1> 1/(1+x)\n");
	printf("2> x*x\n");
	printf("3> 1 + x\n");
	printf("************************\n");
	scanf_s("%d", &fun);
	printf("\n");

	float a, b;
	printf("����������Ҫ����ĺ�������a,b��\n");
	printf("************************\n");
	scanf_s("%f%f", &a, &b);
	printf("\n");

	int n = 1;
	printf("�������������ĵȷ���n��\n");
	printf("************************\n");
	scanf_s("%d", &n);
	printf("\n");

	float h = 0;
	h = (b - a) / (float)n;

	float x, temp = 0;
	for (int i = 1; i < n; i++) {
		x = a + i * h;
		temp += 2 * func(x, fun);
	}

	temp = 1.0 / 2.0 * h * (func(a, fun) + temp + func(b, fun));

	printf("����õ��Ľ���ǣ�%f\n\n", temp);

	system("PAUSE");
	return 0;
}