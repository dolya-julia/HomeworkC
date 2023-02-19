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