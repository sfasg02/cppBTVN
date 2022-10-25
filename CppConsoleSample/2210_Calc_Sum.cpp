#include <iostream>
using namespace std;

int calc_2210_sum()
{
	const int max_length = 100;

	cout << "NOW CALCULATING 2210 S SUM..." << endl;
	int n, x;
	cout << "INPUT N : ";
	cin >> n;
	cout << "INPUT X : ";
	cin >> x;

	float Sum = 0;
	float Temp;
	float TuSo, MauSo;
	TuSo = (float)1 / x;
	MauSo = 0;
	for (int i = 0; i < n; i++) {
		TuSo *= x;
		MauSo += 1;
		Temp = (float)TuSo / MauSo;
		Sum += Temp;
	};
	cout << "S = " << Sum;


	return 0;
}