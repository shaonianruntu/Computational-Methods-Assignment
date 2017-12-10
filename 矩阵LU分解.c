/*
 * 编写矩阵 LU 分解的程序
 */

#include<stdio.h>
#include<math.h>
int main(void)
{
	float A[7][7] = {{ 3,-5,6,4,-2,-3,8 },
                    { 1,1,-9,15,1,-9 ,2 },
                    { 2,-1,7,5,-1,6,11 },
                    { -1,1,3,2,7,-1,-2 },
                    { 4,3,1,-7,2,1,1 },
                    { 2,9,-8,11,-1,-4,-1 },
                    { 7,2,-1, 2,7,-1,9 } };
	float b[7] = { 11,2,29,9,5,8,25 };
	float x[7] = { 0 };
	float Aik, S, temp;
	int i, j, k;
	float max; 
	int col; 
	int size = 7;
	printf("A[][]\n");
	for (i = 0; i<size; i++)
	{
		for (j = 0; j<size; j++)
			printf("%f ", A[i][j]);
		printf("\n");
	}
	printf("b[]\n");
	for (i = 0; i<size; i++)
		printf("%f ", b[i]);
	printf("\n\n");
	for (k = 0; k<size - 1; k++)
	{
		max = fabs(A[k][k]);
		col = k;
		for (i = k; i<size; i++)
		{
			if (max<fabs(A[i][k]))
			{
				max = fabs(A[i][k]);
				col = i;
			}
		}
		printf("col:%d\n", col);
		for (j = k; j<size; j++)
		{
			temp = A[col][j];
			A[col][j] = A[k][j];
			A[k][j] = temp;
		}
		temp = b[col]; b[col] = b[k]; b[k] = temp;

		if (!A[k][k])
			return -1;
		for (i = k + 1; i<size; i++)
		{
			Aik = A[i][k] / A[k][k];
			for (j = k; j<size; j++)
			{
				A[i][j] = A[i][j] - Aik*A[k][j];
			}
			b[i] = b[i] - Aik*b[k];
		}
	}
	printf("A[]\n");
	for (i = 0; i<size; i++)
	{
		for (j = 0; j<size; j++)
			printf("%f ", A[i][j]);
		printf("\n");
	}
	printf("b[]\n");
	for (i = 0; i<size; i++)
		printf("%f ", b[i]);
	printf("\n\n");
	x[size - 1] = b[size - 1] / A[size - 1][size - 1];
	for (k = size - 2; k >= 0; k--)
	{
		S = b[k];
		for (j = k + 1; j<size; j++)
		{
			S = S - A[k][j] * x[j];
		}
		x[k] = S / A[k][k];
	}
	printf("The solution x[]=\n");
	for (i = 0; i<size; i++)
		printf("%f ", x[i]);
	printf("\n");
	return 0;
}
