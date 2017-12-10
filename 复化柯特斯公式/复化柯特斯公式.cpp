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
	printf("   ��������˹��ʽʵ��\n");
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
	for (int i = 0; i < n; i++) {
		x = a + i * h;
		temp += 32 * func(x + 1 / 4, fun);
		temp += 12 * func(x + 1 / 2, fun);
		temp += 32 * func(x + 3 / 4, fun);
		temp += 14 * func(x, fun);
	}
	temp -= 14 * func(a, fun);

	temp = 1.0 / 90.0 * h * (7 * func(a, fun) + temp + 7 * func(b, fun));

	printf("����õ��Ľ���ǣ�%f\n\n", temp);

	system("PAUSE");
	return 0;
}