#include <iostream>
#include <ctime>
using namespace std;
int main() 
{
	unsigned int start_time = clock();
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
	for (int i = 0; i < n1; i++)
	{
		c[i] = new int[m2];
		for (int j = 0; j < m2; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < m1; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "Program running time: " << search_time << endl;
	system("pause");
	return 0;
}


#include <iostream>
#include <omp.h>
using namespace std;
int main()
{
	
	int n1 = 100, m1 = 100;
	int** a = new int* [n1];
	for (int i = 0; i < n1; i++)
	{
		a[i] = new int[m1];
		for (int j = 0; j < m1; j++)
			a[i][j] = rand();
	}
	int n2 = 100, m2 = 100;
	int** b = new int* [n2];
	for (int i = 0; i < n2; i++)
	{
		b[i] = new int[m2];
		for (int j = 0; j < m2; j++)
			b[i][j] = rand();
	}
	double t1 = omp_get_wtime();
	int** c = new int* [n1];
	int i, j, k;
	/*int threadsNum = 3;
	omp_set_num_threads(threadsNum);*/
#pragma omp parallel for schedule(static) shared(a,b,c) private(i,j, k)
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
	double t2 = omp_get_wtime();
	double res_time = t2 - t1;
	cout << "Static program running time: " << res_time << endl;
	double t3 = omp_get_wtime();
	int** d = new int* [n1];
#pragma omp parallel for schedule(dynamic) shared(a,b,c) private(i,j, k)
	for (i = 0; i < n1; i++)
	{
		d[i] = new int[m2];
		for (j = 0; j < m2; j++)
		{
			d[i][j] = 0;
			for (k = 0; k < m1; k++)
				d[i][j] += a[i][k] * b[k][j];
		}
	}
	/*for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}*/
	double t4 = omp_get_wtime();
	double res_time2 = t4 - t3;
	cout << "Dynamic program running time: " << res_time2 << endl;
	system("pause");
	return 0;
}
