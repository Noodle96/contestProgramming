#include<iostream>
using namespace std;


int main(){
    int a = 2147483648;
    long int b = 45;
    long long c = 56;
    string d = "monod";
    float e = 45.6;
    double f = 45.3;
    // cout << a << endl;
    cout << sizeof(a) << endl; // 4
    cout << sizeof(b) << endl; // 8
    cout << sizeof(c) << endl; // 8
    cout << sizeof(d) << endl; // 32
    cout << sizeof(e) << endl; // 4
    cout << sizeof(f) << endl; // 8


    return 0;
}