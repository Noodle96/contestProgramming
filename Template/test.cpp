#include<iostream>
using namespace std;

int lookup[10][10];

void buildLookup(){
    for (int i = 0; i < 10; i++)
		lookup[i][0] = i; 
}

void printMatrix(){
    for(auto e = 0 ; e < 10;e++){
        for (auto l = 0; l < 10; l++)
        {
            cout << lookup[e][l] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    buildLookup();
    printMatrix();
    long long a;
    cout <<"sizeof: " << endl;
    cout << sizeof(a) << endl;
    cout << 234000000000000 - 45000000000000 << endl;
    return 0;
}