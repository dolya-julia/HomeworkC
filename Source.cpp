#include <iostream>
#include <omp.h>
using namespace std;
int main()
{
	double t1 = omp_get_wtime();
	int n1 = 3, m1 = 3;
	int** a = new int*[n1];
	for (int i = 0; i < n1; i++)
	{
		a[i] = new int[m1];
		for (int j = 0; j < m1; j++)
			cin >> a[i][j];
	}
	int n2 = 3, m2 = 3;
	int** b = new int*[n2];
	for (int i = 0; i < n2; i++)
	{
		b[i] = new int[m2];
		for (int j = 0; j < m2; j++)
			cin >> b[i][j];
	}
	int** c = new int*[n1];
	int i, j, k;
	int threadsNum = 3;
	omp_set_num_threads(threadsNum);
#pragma omp parallel for shared(a,b,c) private(i,j, k)
	for (i = 0; i < n1; i++)
	{
		c[i] = new int[m2];
		for (j = 0; j < m2; j++)
		{
			c[i][j] = 0;
			for (k = 0; k < m1; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	double t2 = omp_get_wtime();
	double res_time = t2 - t1;
	cout << "Program running time: " << res_time << endl;
	system("pause");
	return 0;
}