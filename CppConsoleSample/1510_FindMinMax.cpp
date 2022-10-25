#include <iostream>
using namespace std;

int find_min_max_value_in_array()
{
	const int max_length = 100;

	cout << "NOW FINDING MIN VALUE..." << endl;
	int n;
	cout << "INPUT N : ";
	cin >> n;

	int min = INT_MAX;
	int max = INT_MIN;
	int min_postision = -1;
	int max_postision = -1;
	int a[max_length];
	
	for (int i = 0; i < n; i++) {
		cout << "INPUT a[" << i << "]: ";
		cin >> a[i];
		if (a[i] < min) {
			min_postision = i;
			min = a[i];
		}
		if (a[i] > max) {
			max_postision = i;
			max = a[i];
		}
	};

	cout << "MIN VALUE: " << min << " at postision: " << min_postision;
	cout << "MIN VALUE: " << max << " at postision: " << max_postision;

	return 0;
}


//#include <algorithm>
//#include <vector>
// Defining the binary function
//bool comp(int a, int b)
//{
//	return (a < b);
//}
// Finding the smallest of all the numbers
// cout << std::min({ 1, 2, 3, 4, 5, 0, -1, 7 }, comp) << "\n";
