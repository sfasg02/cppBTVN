#include <algorithm>
#include <iostream>
using namespace std;

int sort_2210_2d_array()
{
	const int max_length = 50;

	cout << "NOW SORTING 2D ARRAY..." << endl;
	int m, n;
	cout << "INPUT M : ";
	cin >> m;
	cout << "INPUT N : ";
	cin >> n;

	float Max = INT_MIN;
	int i_max = -1 , j_max = -1;
	float a[max_length][max_length];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "INPUT a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
			if (Max < a[i][j]) {
				i_max = i;
				j_max = j;
				Max = a[i][j];
			}
		}
	};

	cout << "BIGGEST ELEMENT IS " << Max << "AT a[" << i_max << "][" << j_max << "]" << endl;

	cout << "GENERATE 1D B ARRAY TO REDUCE FOR LOOP THEN SORT" << endl;

	float b[max_length* max_length];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			b[i * n + j] = a[i][j];
			cout << "Element at b[" << i * n + j << "]: ";
			cout << b[i * n + j] << endl;
		}
	}

	float temp;
	cout << "SORTING FROM SMALLEST TO BIGGEST USING BUBBLE SORT..." << endl;
	for (int i = 0; i < m * n + 1; i++) {
		for (int j = i; j < m * n + 1; j++) {
			if (b[i] > b[j]) {
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			};
		}
	}
	//Co the dung ham sort co san trong thu vien algorithm

	cout << "CONVERT BACK TO 2D ARRAY" << endl;
	for (int i = 0; i < m * n; i++) {
		cout << "Element at b[" << i << "] =  " << b[i] << " >> " << "a[" << i / n << "][" << i % n << "]" << endl;
		a[i / n][i % n] = b[i];
//		cout << i / n << " " << i % n << endl;
	};

	cout << "NOW PRINTING RESULT:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Element at a[" << i
				<< "][" << j << "]: ";
			cout << a[i][j] << endl;
		}
	}


	return 0;
}