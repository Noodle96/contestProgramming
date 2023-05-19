#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
using MII = map<int,int>;
using MSI = multiset<int>;

void printMSI( MSI &apartmentSizeApplicant){
	for(auto it = apartmentSizeApplicant.begin() ; it != apartmentSizeApplicant.end() ; it++){
		cout << * it << " " ;
	}; cout << endl;
}
void printMII( MII &apartmentSizeApplicant){
	for(auto it = apartmentSizeApplicant.begin() ; it != apartmentSizeApplicant.end() ; it++){
		cout << it->first << " -> " << it->second << endl;
	}
}

int f(MII &apartmentSizeApplicant, VI &apartmentSize, int k){ // O(mlogn)
	MII::iterator it;
	int cont = 0;
	for(int e = 0 ; e < apartmentSize.size(); e++){ // O(m)
		//cout << "\n\napartmentSize[e]: " << apartmentSize[e] << endl;
		//cout << "cont: "<< cont << endl;
		
		
		
		it = apartmentSizeApplicant.lower_bound(apartmentSize[e]);// O(log n)
		if(it != apartmentSizeApplicant.end()){
			
			//cout << it->first << endl;
		//if(apartmentSizeApplicant.count(it->first) > 0){
			//cout << "inside" << endl;
			if(it->first - apartmentSize[e] <=2*k){
				cont++;
				(it->second)--;
				//cout << "test: " << apartmentSizeApplicant.count(it->first) << endl;
				if(it->second < 1) apartmentSizeApplicant.erase(it);
				//printMII(apartmentSizeApplicant);
			}
		//}
		
		
		}
		             
	}
	return cont;
}
int main(){
	
	int n,m,k;  cin>>n>>m>>k;
	int temp;
	MII apartmentSizeApplicant;
	//MSI apartmentSizeApplicant;
	for(int e = 0 ; e < n; e++){
		cin>>temp;
		//apartmentSizeApplicant.insert(temp+k);
		apartmentSizeApplicant[temp+k]++;
	}
	//for(auto it = apartmentSizeApplicant.begin() ; it != apartmentSizeApplicant.end() ; it++){
	//	cout << * it << " " ;
	//}; cout << endl;
	 
	vector<int> apartmentSize(m);
	for(auto &e : apartmentSize ) cin>>e;
	sort(apartmentSize.begin(), apartmentSize.end());
	cout << f(apartmentSizeApplicant,apartmentSize, k) << endl;
	return 0;
}
