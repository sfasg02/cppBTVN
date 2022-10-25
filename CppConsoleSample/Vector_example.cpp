#include <vector>;
#include <algorithm>;
#include <iostream>;
using namespace std;

int vector_example()
{
    vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

    sort(v.begin(), v.end());

    cout << "Sorted \n";
    for (auto x : v)
        cout << x << " ";

    return 0;
}

//int validate() {
    //double radius;
    //cout << "Input Radius: ";
    //while (!(cin >> radius)) {
    //    cout << "Bad value!" << endl;
    //    cin.clear();
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //}
    //cout << "OK" << endl;
    //cout << radius;
    // 
    //double x;
    //while (1) {
    //    if (cin >> x) {
    //        // valid number
    //        cout << x;

    //        break;
    //    }
    //    else {
    //        // not a valid number
    //        cout << "Invalid Input! Please input a numerical value." << endl;
    //        cin.clear();
    //        while (cin.get() != '\n'); // empty loop
    //    }
    //}
//    return 0;
//
//};
