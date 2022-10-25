#include <iostream>
using namespace std;

int calc_s_sum()
{
	const int max_length = 100;

	cout << "NOW CALCULATING S SUM..." << endl;
	int n;
	cout << "INPUT N : ";
	cin >> n;

	float Sum = 0;
	float Temp;

	for (int i = 0; i < n; i++) {
		Temp = (float) 1 / (i + 1);
		Sum += Temp;
	};
	cout << "S = " << Sum;


	return 0;
}