#include <iostream>
using namespace std;
using US = unsigned short;

int main(){
    US t;
    US X,Y;
    cin>>t;
    for(auto e = 0 ;e < t ; e++){
        cin >> X;
        cin >> Y;
        cout << ((X+Y) > 6 ? "YES" : "NO") << endl;
    }
    return 0;
}
