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






#include <thread>
#include <iostream>
#include <omp.h>
using namespace std;
void func1(int **a, int ** b) 
{
	for (int i = 0; i < 10; i++)
	{
		a[i] = new int[10];
		for (int j = 0; j < 10; j++)
			a[i][j] = rand()% 10;
	}
	for (int i = 0; i < 10; i++)
	{
		b[i] = new int[10];
		for (int j = 0; j < 10; j++)
			b[i][j] = rand() % 10;
	}
}
void func2(int** a, int** b, int** d)
{
	for (int i = 0; i < 10; i++)
	{
		d[i] = new int[10];
		for (int j = 0; j < 10; j++)
		{
			d[i][j] = 0;
			for (int k = 0; k < 10; k++)
				d[i][j] += a[i][k] * b[k][j];
		}
	}
}
int main()
{
	int** a = new int* [10];
	int** b = new int* [10];
	int** d = new int* [10];
	
	thread first(func1, a, b);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	/*func1(a, b);
	thread second(func2, a, b, d);
	func2(a, b, d);
	cout << "Performed functions func1 and func2";
	first.join();
	second.join();
	func1(a, b);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << b[i][j] << " ";
		cout << endl;
	}
	func2(a, b, d);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}*/
	cout << "Threads ended";
	return 0;
}
