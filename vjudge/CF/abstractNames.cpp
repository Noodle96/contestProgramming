#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;

using namespace std;

bool isVowel(char x){
    if (x == 'a' || x == 'e' || x == 'i'
        || x == 'o'|| x == 'u')
        return true;
    return false;
}

void solve(){
	bool flag = true;
	int n; cin>>n;
	string str1,str2;
	for(int e = 0 ;e < n ; e++){
		cin>>str1>>str2;
		flag = true;
		if(str1.size() != str2.size()){
			cout << "No" << endl;continue;
		}
		for(int j = 0 ; j < str1.size(); j++){
			if(str1[j] != str2[j]){
				if(isVowel(str1[j])  && isVowel(str2[j]))continue;
				else {
					cout << "No" << endl;flag = false;
					break;
					
				}
			}
		}
		if(flag) cout << "Yes" << endl;
	}
	
}
int main(){
	solve();
	return 0;
}