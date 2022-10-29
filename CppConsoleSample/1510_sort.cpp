#include <vector>;
#include <algorithm>;
#include <iostream>;
#include <string>;
#include <cctype>;
#include <cstdio>;
#include <windows.h>;
#include "sort.h";
#pragma execution_character_set( "utf-8" )
using namespace std;



// Driver program to test above functions
int sort_1510_arr()
{
    const int MAX_LENGTH = 50;
    SetConsoleOutputCP(65001); // Chuyển sang console log bằng Unicode (UTF-8 with signature) để tránh vỡ font chữ.
    cout << "NOW SORTING ARRAY..." << endl;
    int n;
    int a[MAX_LENGTH];
    cout << "NHẬP SỐ PHẦN TỬ TRONG MẢNG: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]: "; cin >> a[i];
    };
    cout << "MẢNG VỪA NHẬP: " << endl;
    printArray(a, n);

    selectionSort(a, n);
    cout << "Sorted array: \n";
    printArray(a, n);
    return 0;
}