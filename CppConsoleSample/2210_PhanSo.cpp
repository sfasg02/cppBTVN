#include <iostream>
#include <cstdio>
#include <windows.h>
#pragma execution_character_set( "utf-8" )
using namespace std;

class Fraction
{
private:
    int numerator, denominator;
public:
    Fraction()
    {
        numerator = 1;
        denominator = 1;
    } // => Handle trường hợp cần khai báo mà chưa muốn đưa data vào. Trường hợp này tử số và mẫu số không có giá trị
    Fraction(int n, int d)
    {
        numerator = n;
        if (d == 0)
        {
            cout << "ERROR: ATTEMPTING TO DIVIDE BY ZERO" << endl;
            exit(0); // will terminate the program if division by 0 is attempted
        }
        else
            denominator = d;
    }

    Fraction Redure() {
        int n = numerator / gcd(numerator, denominator);
        int d = denominator / gcd(numerator, denominator);
        return Fraction(n, d);
    };
    Fraction Sum(Fraction otherFraction)
    {
        int n = numerator * otherFraction.denominator + otherFraction.numerator * denominator;
        int d = denominator * otherFraction.denominator;
        return Fraction(n / gcd(n, d), d / gcd(n, d));
    }
    Fraction Difference(Fraction otherFraction)
    {
        int n = numerator * otherFraction.denominator - otherFraction.numerator * denominator;
        int d = denominator * otherFraction.denominator;
        return Fraction(n / gcd(n, d), d / gcd(n, d));
    }
    Fraction Product(Fraction otherFraction)
    {
        int n = numerator * otherFraction.numerator;
        int d = denominator * otherFraction.denominator;
        return Fraction(n / gcd(n, d), d / gcd(n, d));
    }
    Fraction Division(Fraction otherFraction) // => Chia 2 phân số, không có trong đề bài.
    {
        int n = numerator * otherFraction.denominator;
        int d = denominator * otherFraction.numerator;
        return Fraction(n / gcd(n, d), d / gcd(n, d));
    }

    int gcd(int n, int d)
    {
        int remainder;
        while (d != 0)
        {
            remainder = n % d;
            n = d;
            d = remainder;
        }
        return n;
    }
    void show()
    {
        if (denominator == 1)
            cout << numerator << endl;
        else
            cout << numerator << "/" << denominator << endl;
    }
};

int PhanSo_2210()
{
    SetConsoleOutputCP(65001); // Chuyển sang console log bằng Unicode (UTF-8 with signature) để tránh vỡ font chữ.
    cout << "NOW CALCULATING WITH TWO FRACTION..." << endl;
    int temp_numerator, temp_denominator;

    cout << "Nhập tử số phân số 1: ";
    cin >> temp_numerator;
    cout << "Nhập mẫu số phân số 1: ";
    cin >> temp_denominator;
    Fraction PhanSo1(temp_numerator, temp_denominator);
    cout << "Phân số 1 ở dạng chưa rút gọn: "; PhanSo1.show();
    cout << "Phân số 1 ở dạng rút gọn: "; PhanSo1.Redure().show();
    cout << endl;

    cout << "Nhập tử số phân số 2: ";
    cin >> temp_numerator;
    cout << "Nhập mẫu số phân số 2: ";
    cin >> temp_denominator;
    Fraction PhanSo2(temp_numerator, temp_denominator);
    cout << "Phân số 2 ở chưa dạng rút gọn: "; PhanSo2.show();
    cout << "Phân số 2 ở dạng rút gọn: "; PhanSo2.Redure().show();
    cout << endl;

    // Có thể gán PhanSo1 = PhanSo1.Redure() để tối ưu, tương tự PhanSo2. Có thời gian quay lại sửa sau.

    cout << "Tổng 2 phân số: ";
    PhanSo1.Sum(PhanSo2).show();

    cout << "Tích 2 phân số: ";
    PhanSo1.Product(PhanSo2).show();

    return 0;
}