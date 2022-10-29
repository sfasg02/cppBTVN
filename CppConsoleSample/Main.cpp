// CppConsoleSample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BTVN_BienTran.h"
#include <cstdio>
#include <windows.h>
//#include "1510_sort.cpp"

#pragma execution_character_set( "utf-8" )
using namespace std;

void main()
{
    SetConsoleOutputCP(65001); // Chuyển sang console log bằng Unicode (UTF-8 with signature) để tránh vỡ font chữ.
    cout << "NHẬP SỐ ĐỂ CHỌN BÀI TẬP!" << endl;
    cout << "LIST BÀI TẬP VỀ NHÀ: " << endl;
    cout << "1: (15/10) Tìm min max của dãy số thực." << endl;
    cout << "2: (15/10) Tính tổng S=1+1/2+...+1/n." << endl;
    cout << "3: (15/10) Sort array n số nguyên bằng selection, insert, bubble, quicksort, merge." << endl;
    cout << "4: (15/10) Quản lý sinh viên." << endl;
    cout << "5: (22/10) Calc S = 1 + x/2 + (x^2)/3 + ... + (x^n)/(n+1)." << endl;
    cout << "6: (22/10) Sorting 2D array (smallest to biggest)." << endl;
    cout << "7: (22/10) Xây dựng chương trình thao tác với phân số." << endl;
    cout << "8: (22/10) Xây dựng chương trình thao tác với vector (ngầm hiểu là vector toán học, không phải kiểu vector của STL)." << endl;
    cout << "9: (26/10) Xây dựng chương trình quản lý hóa đơn vật tư." << endl;
    cout << "Lựa chọn của bạn: ";
    int LuaChon;
    cin >> LuaChon;

    switch (LuaChon)
    {
    case 1: find_min_max_value_in_array(); break;
    case 2: calc_s_sum(); break;
    case 3: sort_1510_arr(); break;
    case 4: Student_management(); break;
    case 5: calc_2210_sum(); break;
    case 6: sort_2210_2d_array(); break;
    case 7: PhanSo_2210(); break;
    case 8: vector_calculate(); break;
    case 9: bill_of_material_management(); break;
    default:
        cout << "Tính năng chưa implement...";
        break;
    }

}   

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
