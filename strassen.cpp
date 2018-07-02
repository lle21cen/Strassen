#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 512

void printArr(int n, int **a);
void strassen(int n, int *a[], int *b[], int *c[]);
void nomalWay(int n, int **a, int **b, int **c);

int main() {
	srand(time(NULL));

	time_t time1, time2;

	int **a = (int**)malloc(sizeof(int*)*N);
	int **b = (int**)malloc(sizeof(int*)*N);
	int **c = (int**)malloc(sizeof(int*)*N);
	int **d = (int**)malloc(sizeof(int*)*N);

	for (int i=0; i<N; i++) {
		a[i] = (int*)malloc(sizeof(int)*N);
		b[i] = (int*)malloc(sizeof(int)*N);
		c[i] = (int*)malloc(sizeof(int)*N);
		d[i] = (int*)malloc(sizeof(int)*N);
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			a[i][j] = rand()%10;
			b[i][j] = rand()%10;
		}
	}
//	printArr(N, a);
//	printArr(N, b);
	
	time1 = clock();
	strassen(N, a, b, c);
	printf("스트라센 걸린 시간: %f\n", (float)(clock()-time1)/CLOCKS_PER_SEC);
//	printArr(N, c);

	time2 = clock();
	nomalWay(N, a, b, d);
	printf("일반 행렬곱 걸린 시간: %f\n", (float)(clock()-time2)/CLOCKS_PER_SEC);
//	printArr(N, d);
}

void strassen(int n, int **a, int **b, int **c) {
	int p=0;
	int h = n/2;
	if (n <= 2) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				for(p=0; p<n; p++) {
					c[i][j] += (a[i][p] * b[p][j]);
				}
			}
		}
//		printArr(n, c);
		return;
	}

	int **a11 = (int**)malloc(sizeof(int*)*h);
	int **a12 = (int**)malloc(sizeof(int*)*h);
	int **a21 = (int**)malloc(sizeof(int*)*h);
	int **a22 = (int**)malloc(sizeof(int*)*h);

	int **b11 = (int**)malloc(sizeof(int*)*h);
	int **b12 = (int**)malloc(sizeof(int*)*h);
	int **b21 = (int**)malloc(sizeof(int*)*h);
	int **b22 = (int**)malloc(sizeof(int*)*h);
	
	int **temp1 = (int**)malloc(sizeof(int*)*h);
	int **temp2 = (int**)malloc(sizeof(int*)*h);
	int **temp3 = (int**)malloc(sizeof(int*)*h);
	int **temp4 = (int**)malloc(sizeof(int*)*h);
	int **temp5 = (int**)malloc(sizeof(int*)*h);
	int **temp6 = (int**)malloc(sizeof(int*)*h);
	int **temp7 = (int**)malloc(sizeof(int*)*h);
	int **temp8 = (int**)malloc(sizeof(int*)*h);
	int **temp9 = (int**)malloc(sizeof(int*)*h);
	int **temp10 = (int**)malloc(sizeof(int*)*h);

	int **m1 = (int**)malloc(sizeof(int*)*h);
	int **m2 = (int**)malloc(sizeof(int*)*h);
	int **m3 = (int**)malloc(sizeof(int*)*h);
	int **m4 = (int**)malloc(sizeof(int*)*h);
	int **m5 = (int**)malloc(sizeof(int*)*h);
	int **m6 = (int**)malloc(sizeof(int*)*h);
	int **m7 = (int**)malloc(sizeof(int*)*h);

	for (int i=0; i<h; i++) {
		a11[i] = (int*)malloc(sizeof(int)*h);
		a12[i] = (int*)malloc(sizeof(int)*h);
		a21[i] = (int*)malloc(sizeof(int)*h);
		a22[i] = (int*)malloc(sizeof(int)*h);

		b11[i] = (int*)malloc(sizeof(int)*h);
		b12[i] = (int*)malloc(sizeof(int)*h);
		b21[i] = (int*)malloc(sizeof(int)*h);
		b22[i] = (int*)malloc(sizeof(int)*h);

		temp1[i] = (int*)malloc(sizeof(int*)*h);
		temp2[i] = (int*)malloc(sizeof(int*)*h);
		temp3[i] = (int*)malloc(sizeof(int*)*h);
		temp4[i] = (int*)malloc(sizeof(int*)*h);
		temp5[i] = (int*)malloc(sizeof(int*)*h);
		temp6[i] = (int*)malloc(sizeof(int*)*h);
		temp7[i] = (int*)malloc(sizeof(int*)*h);
		temp8[i] = (int*)malloc(sizeof(int*)*h);
		temp9[i] = (int*)malloc(sizeof(int*)*h);
		temp10[i] = (int*)malloc(sizeof(int*)*h);

		m1[i] = (int*)malloc(sizeof(int)*h);
		m2[i] = (int*)malloc(sizeof(int)*h);
		m3[i] = (int*)malloc(sizeof(int)*h);
		m4[i] = (int*)malloc(sizeof(int)*h);
		m5[i] = (int*)malloc(sizeof(int)*h);
		m6[i] = (int*)malloc(sizeof(int)*h);
		m7[i] = (int*)malloc(sizeof(int)*h);
	}

	for (int i=0; i<h; i++) {
		for (int j=0; j<h; j++) {
			a11[i][j] = a[i][j];
			b11[i][j] = b[i][j];
			a12[i][j] = a[i][j+h];
			b12[i][j] = b[i][j+h];

			a21[i][j] = a[i+h][j];
			b21[i][j] = b[i+h][j];

			a22[i][j] = a[i+h][j+h];
			b22[i][j] = b[i+h][j+h];
		}
	}

	for (int i=0; i<h; i++) {
		for (int j=0; j<h; j++) {
			temp1[i][j] = a11[i][j] + a22[i][j];
			temp2[i][j] = b11[i][j] + b22[i][j];
		}
	}
	for (int i=0; i<h; i++) {
		for (int j=0; j<h; j++) {
			temp1[i][j] = a11[i][j] + a22[i][j];
			temp2[i][j] = b11[i][j] + b22[i][j];
			temp3[i][j] = a21[i][j] + a22[i][j];
			temp4[i][j] = b12[i][j] - b22[i][j];
			temp5[i][j] = b21[i][j] - b11[i][j];
			temp6[i][j] = a11[i][j] + a12[i][j];
			temp7[i][j] = a21[i][j] - a11[i][j];
			temp8[i][j] = b11[i][j] + b12[i][j];
			temp9[i][j] = a12[i][j] - a22[i][j];
			temp10[i][j] = b21[i][j] + b22[i][j];
		}
	}

	strassen(h, temp1, temp2, m1);
	strassen(h, temp3, b11, m2);
	strassen(h, a11, temp4, m3);
	strassen(h, a22, temp5, m4);
	strassen(h, temp6, b22, m5);
	strassen(h, temp7, temp8, m6);
	strassen(h, temp9, temp10, m7);

	for (int i=0; i<h; i++) {
		for (int j=0; j<h; j++) {
			c[i][j] = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
			c[i][j+h] = m3[i][j] + m5[i][j];
			c[i+h][j] = m2[i][j] + m4[i][j];
			c[i+h][j+h] = m1[i][j] + m3[i][j] - m2[i][j] + m6[i][j];
		}
	}

	for (int i=0; i<h; i++) {
		free(a11[i]), free(a12[i]), free(a21[i]), free(a22[i]);
		free(b11[i]), free(b12[i]), free(b21[i]), free(b22[i]);
		free(temp1[i]), free(temp2[i]), free(temp3[i]), free(temp4[i]), free(temp5[i]); 
		free(temp6[i]), free(temp7[i]), free(temp8[i]), free(temp9[i]), free(temp10[i]);
		free(m1[i]), free(m2[i]), free(m3[i]), free(m4[i]), free(m5[i]), free(m6[i]), free(m7[i]);
	}
	free(a11), free(a12), free(a21), free(a22);
	free(b11), free(b12), free(b21), free(b22);
	free(temp1), free(temp2), free(temp3), free(temp4), free(temp5); 
	free(temp6), free(temp7), free(temp8), free(temp9), free(temp10);
	free(m1), free(m2), free(m3), free(m4), free(m5), free(m6), free(m7);
}

void nomalWay(int n, int **a, int **b, int **c) 
{
	int p = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for(p=0; p<n; p++) {
				c[i][j] += (a[i][p] * b[p][j]);
			}
		}
	}
}
void printArr(int n, int **a) {
	for (int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			printf("%2d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}