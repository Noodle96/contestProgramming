#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define msg(str,str2) cout << str << str2<< endl
using namespace std;
void convertUpper(string &str){
	for(int e = 0 ; e < str.size(); e++){
		str[e] =toupper(str[e]);
	}
}
void solve(){
	string nameBinder;
	cin.ignore();
	getline(std::cin, nameBinder);
	// msg("nameBinder: ", nameBinder);

	int n,m,b; cin>>m>>n>>b;
	// msg("n: ",n);
	// msg("m: ",m);
	// msg("b",b);

	map<string, int> map_ingredientes;
	string ingrediente; int costoIngrediente;
	//seteando el ingrediente y su costo
	for(int e = 0 ; e < m; e++){
		cin>>ingrediente>>costoIngrediente;
		map_ingredientes[ingrediente] = costoIngrediente;
	}
	// msg("map_ingredientes: ","");
	// for(auto it = map_ingredientes.begin(); it != map_ingredientes.end() ; it++){
	// 	cout << it->first << " : " << it->second << endl;
	// }

	//seteando las recetas
	vector<pair<int,string>> vector_recetas;
	string nameReceta;
	int cantidad;
	int cant_ingrediente;
	for(int e = 0 ;e < n ; e++){
		cin.ignore();
		getline(std::cin, nameReceta);
		// msg("nameReceta: ", nameReceta);
		cin>>cant_ingrediente;
		// msg("cant_ingrediente: ", cant_ingrediente);
		int total = 0;
		for(int j = 0 ;j < cant_ingrediente ;j++){
			cin>>ingrediente>>cantidad;
			total += (cantidad * map_ingredientes[ingrediente]);
		}
		// msg("total: ", total);
		vector_recetas.push_back(make_pair(total, nameReceta));
	}

	//rendering output
	convertUpper(nameBinder);
	msg(nameBinder,"");
	sort(all(vector_recetas));
	int existReceta = 0;
	for(auto it = vector_recetas.begin() ; it != vector_recetas.end(); it++){
		if(it->first <= b){
			msg(it->second,"");
			existReceta ++;
		}else break;
	}
	if(!existReceta) msg("Too expensive!","");
}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif

	int binders; cin>>binders;
	int casos = binders;
	while(binders--){
		solve();
		// if(casos > 1) cout << endl;
		// casos --;
		cout << endl;
	}
	return 0;
}