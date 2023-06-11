#include <bits/stdc++.h>
using namespace std;

bool comparefn(pair<int,string> &a, pair<int,string> &b)
{
    if(a.first!=b.first) return a.first<b.first;
    return false;
}
int calculate(string &str, int n){
	int cont = 0 ;
	for(int e = 0 ; e < n; e++){
		for(int j  = e+1 ;j < n ; j++){
			if(str[e] > str[j]) cont++;
		}
	}
	return cont;
}

// vector< vector<pair<int,string>> > &r4esultados
// vector<   map<int, vector<string>>  > &resultados 
void proccess(int &m_copy){
	int n,m;
	string stringTemp;
	// vector<string>dataset;
	// vector< pair<int, string>> dataset;
	map<int, vector<string>> dataset;
	cin>>n>>m;
	for(int e = 0 ; e < m; e++){
		cin>>stringTemp;
		dataset[calculate(stringTemp,n)].push_back(stringTemp);
		// dataset.push_back(make_pair( calculate(stringTemp, n), stringTemp ));
		// dataset[calculate(stringTemp,n)].push_back(stringTemp);
		
		// dataset.push_back(stringTemp);
	}

	// sort(dataset.begin(),dataset.end(), comparefn );
	// for(int e = 0 ;e < m ; e++){
	// 	cout << dataset[e].first << " "<<dataset[e].second << endl;
	// }


	for(auto it = dataset.begin() ; it != dataset.end(); it++){
		for(auto ot = it->second.begin() ; ot != it->second.end(); ot++){
			cout << *ot << endl;
		}
	}
	if(m_copy != 1) cout << endl;
	m_copy --;

	// resultados.push_back(dataset);


}
int main(){
	int M; cin>>M;
	int M_copy = M;
	// vector< vector<pair<int,string>> > results;
	// vector<   map<int, vector<string>>  > resultados;
	while(M--){
		
		// proccess(results);
		// proccess(resultados);
		proccess(M_copy);
	}

	//PROCESS RESULTADOS
	// int e = 0;
	// for(;e < resultados.size()-1 ; e++){
	// 	for(auto it = resultados[e].begin() ; it != resultados[e].end(); it++){
	// 		for(auto ot = it->second.begin() ; ot != it->second.end(); ot++){
	// 			cout << *ot << endl;
	// 		}
	// 	}
	// 	// cout << endl;
	// }
	// for(auto it = resultados[e].begin() ; it != resultados[e].end(); it++){

	// 		auto ot = it->second.begin() ;
	// 		for(; ot != it->second.end(); ot++){
	// 			cout << *ot << endl;
	// 		}
	// }



	// map<int, vector<int> > map;
	// int key,value;
	// while(true){
	// 	cin>> key>>value;
	// 	if(key == 1000) break;
		
	// 	map[key].push_back(value);
	// }
	// for(auto it = map.begin() ; it != map.end(); it++){
	// 	for(auto ot = it->second.begin() ; ot != it->second.end(); ot++){
	// 		cout << *ot << " ";
	// 	}cout << endl;
	// }

	return 0;
}