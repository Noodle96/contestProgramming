#include <iostream>
using namespace std;

int main(){
    long long number;
    cin>>number;
    
    while(true){
        if(number == 1){
            break;
        }
        cout << number << " ";
        
        if(number%2==0){
            number /=2;
        }
        else{
            number = number*3 +1;
        }
        
    }
    cout << 1 << endl;
    return 0;
}
