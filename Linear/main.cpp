#include <iostream>
#include <string>
#include <complex>
#include "Linear.h"
using namespace std;
const int cloT = 2;
const string types[cloT] = {"1. Float", "2. Complex"};
const int cloM = 4;
const string manipulations[cloM] = {"1. Addition",
                             "2. Subtraction",
                             "3. Scalar multiplication",
                             "4. Calculating a value for given argument values"};
const string input1Lin = "Enter the first linear form";
const string input2Lin = "Enter the second linear form";
const string inputConst = "Enter the constant";
const string inputLinApproved = "You entered:";
const string Res = "Result:";
const string inputX = "Enter a value of X";



template<typename T>
void dialog()
{
    Linear<T> Lin1;
    Linear<T> Lin2;
    Linear<T> Lin3;
    for (int i = 0; i <cloM;i++)
    {
        cout << manipulations[i] <<endl;
    }
    int choice;
    cin >> choice;
    switch (choice)
    {
        case 1:
            cout << input1Lin << endl;
            cin >>  Lin1;
            cout << inputLinApproved << endl;
            cout << Lin1 << endl;

            cout << input2Lin << endl;
            cin >>  Lin2;
            cout << inputLinApproved << endl;
            cout << Lin2 << endl;

            Lin3 = Lin1 + Lin2;
            cout << Res << endl;
            cout << Lin3 << endl;
            break;

        case 2:
            cout << input1Lin << endl;
            cin >>  Lin1;
            cout << inputLinApproved << endl;
            cout << Lin1 << endl;

            cout << input2Lin << endl;
            cin >>  Lin2;
            cout << inputLinApproved << endl;
            cout << Lin2 << endl;

            Lin3 = Lin1 - Lin2;
            cout << Res << endl;
            cout << Lin3 << endl;
            break;

        case 3:
            cout << input1Lin << endl;
            cin >>  Lin1;
            cout << inputLinApproved << endl;
            cout << Lin1 << endl;

            cout << inputConst << endl;
            float a;
            cin >> a;

            Lin3 = Lin1*a;
            cout << Res << endl;
            cout << Lin3 << endl;
            break;

        case 4:
            cout << input1Lin << endl;
            cin >>  Lin1;
            cout << inputLinApproved << endl;
            cout << Lin1 << endl;

            DynamicArray<T> array;
            array.Resize(Lin1.GetDimension()-1);
            for (int i = 0; i <Lin1.GetDimension()-1;i++)
            {
                T a;
                cout <<inputX<<(i+1)<<";"<<endl;
                cin >> a;
                array.Set(i,a);
            }
            cout << Res << endl;
            cout << Lin1.calc(array) << endl;
            break;
    }
}

int main() {
    cout << "Enter data type: "<<endl;
    for (int i = 0; i <cloT;i++)
    {
        cout << types[i] <<endl;
    }
    int choice;
    cin >> choice;
    switch (choice)
    {
        case 1:
            dialog<float>();
            break;

        case 2:
            dialog<complex<float>>();
            break;
    }

    return 0;
}
