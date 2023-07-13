#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define msg(str,str2) cout << str << str2<< endl
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

class Nodo;
unordered_map<string,Nodo *> familyTree;
unordered_map<string, int> consulta_barrido;
vector<int> grado;

class Nodo{
	private:
		char sexo;
		vector<string> hijos;
		vector<string> padres;
		string pareja;
		// string papa;
		// string mama;
	public:
		Nodo(char sexo){
			this->sexo = sexo;
			// this->papa = "";
			// this->mama = "";
			this->pareja = "";
			padres.resize(2);
			for(int e = 0 ; e < 2; e++){
				this->padres[e] ="";
			}
		}
		~Nodo(){}
		void setPapa(string father){this->padres[0] = father;}
		void setMama(string mother){this->padres[1] = mother;}
		void setPareja(string parej){this->pareja = parej;}

		char getSexo(){return this->sexo;}
		string getPapa(){return this->padres[0];}
		string getMama(){return this->padres[1];}
		string getPareja(){return this->pareja;}
		vector<string> getParents(){return this->padres;}

		void addHijo(string son){this->hijos.pb(son);}
		bool haveParents(){
			auto parents = padres;
			int cont = 0 ;
			for(auto it = parents.begin() ; it != parents.end(); it++){
				if(it->size() == 0) cont++;
			}
			if(cont ==  2) return false;
			return true;
		}
};

void setHombres(){
	fstream file;
	file.open("hombres.txt", ios::in); 
	string line;
	while(getline(file, line)){
		familyTree[line] = new Nodo('M'); 
	}      
}
void setMujeres(){
	fstream file;
	file.open("mujeres.txt", ios::in); 
	string line;
	while(getline(file, line)){
		familyTree[line] = new Nodo('F'); 
	} 
}

void setPadres(){
	fstream file;
	file.open("padres.txt", ios::in); 
	string line, padre, hijo;
	while(getline(file, line)){
		stringstream S; S <<line;
		S >> padre >> hijo;
		// msg("padre: ", padre);
		// msg("hijo: ", hijo);
		// familyTree[line] = new Nodo('F'); 
		if(familyTree.count(padre) > 0 && familyTree.count(hijo)>0){
			familyTree[padre]->addHijo(hijo);
			familyTree[hijo]->setPapa(padre);
		}else{
			cerr << "setPadres say: Padre: " << padre << " or hijo: " << hijo << " no exiten in DB" << endl; 
			return;
		}
		
	} 
}

void setMadres(){
	fstream file;
	file.open("madres.txt", ios::in); 
	string line, madre, hijo;
	while(getline(file, line)){
		stringstream S; S <<line;
		S >> madre >> hijo;
		// msg("padre: ", word1);
		// msg("hijo: ", word2);
		// familyTree[line] = new Nodo('F'); 
		if(familyTree.count(madre) > 0 && familyTree.count(hijo)>0){
			familyTree[madre]->addHijo(hijo);
			familyTree[hijo]->setMama(madre);
		}else{
			cerr << "setMadres say: Madre: " << madre << " or hijo: " << hijo << " no exiten in DB" << endl; 
			return;
		}
	} 
}
void setParejas(){
	// Alberto Amanda
	fstream file;
	file.open("parejas.txt", ios::in);
	string line, parejaH, parejaM;
	while(getline(file,line)){
		stringstream S; S << line;
		S >> parejaH >> parejaM;
		if(familyTree.count(parejaH) > 0 && familyTree.count(parejaM) > 0 ){
			familyTree[parejaH]->setPareja(parejaM);
			familyTree[parejaM]->setPareja(parejaH);
		}else{
			cerr << "setParejas say: ParejaH: " << parejaH << " or ParejaM: " << parejaM << " no exiten in DB" << endl; 
			return;
		}
	}
}
void readData(){
		setHombres();
		setMujeres();
		setPadres();
		setMadres();
		setParejas();
}

void dfs_barrido(string persona1, int length = 0){
	//map the current person
	consulta_barrido[persona1] = length;

	if( !familyTree[persona1]->haveParents() ){
		return;
	}
	if(familyTree[persona1]->getPapa().size() != 0){
		dfs_barrido(familyTree[persona1]->getPapa(), length+1);
	}
	if(familyTree[persona1]->getMama().size() != 0){
		dfs_barrido(familyTree[persona1]->getMama(), length+1);
	}

}
void dfs_stop(string persona2, int length = 0){
	// msg("persona2: ",persona2);
	if(consulta_barrido.count(persona2) > 0){ // existe
		// msg("if","");
		consulta_barrido[persona2] += length;
		grado.pb(consulta_barrido[persona2]);
		return;
	}else{
		// cout << "else" << endl;
		consulta_barrido[persona2] = length;
	}
	if( !familyTree[persona2]->haveParents() ) return;
	if(familyTree[persona2]->getPapa().size() != 0){
		dfs_stop(familyTree[persona2]->getPapa(), length+1);
	}
	if(familyTree[persona2]->getMama().size() != 0){
		dfs_stop(familyTree[persona2]->getMama(), length+1);
	}

}
void query(string persona1, string persona2){
	//CASE01: [PERSONA1] with [PERSONA2]
	dfs_barrido(persona1);
	dfs_stop(persona2);
	if(!grado.empty()){
			cout << "C : " << grado[0] << endl;
	}else{
		//clear data to read new query
		consulta_barrido.clear();
		grado.clear();
		//CASE02: [PERSONA1] with [PERSONA2]->PAREJA
		if(familyTree[persona2]->getPareja().size() != 0){
			dfs_barrido(persona1);
			dfs_stop(familyTree[persona2]->getPareja());
		}
		if(!grado.empty()){
			cout << "A : " << grado[0] << endl;
		}else{
			consulta_barrido.clear();
			grado.clear();
			//CASE03: [PERSONA1]->PAREJA with [PERSONA2]
			if(familyTree[persona1]->getPareja().size() != 0){
				dfs_barrido(familyTree[persona1]->getPareja());
				dfs_stop(persona2);
			}
			if(!grado.empty()){
				cout << "Afinidad : " << grado[0] << endl;
			}
			else{
				consulta_barrido.clear();
				grado.clear();
				//CASE04: [PERSONA1]->PAREJA with [PERSONA2]->PAREJAS
				if(familyTree[persona1]->getPareja().size() != 0 && familyTree[persona2]->getPareja().size() != 0){
					dfs_barrido(familyTree[persona1]->getPareja());
					dfs_stop(familyTree[persona2]->getPareja());
				}
				if(!grado.empty()){
					cout << "Afinidad : " << grado[0] << endl;
				}else{
					cout << "No se relacionan" << endl;
				}
			}
		}
	}
	//clear data to read new query
	consulta_barrido.clear();
	grado.clear();
}

int main(){
	readData();
	string persona1, persona2;
	while(cin>>persona1>>persona2){
		if(persona1 == "0" && persona2 == "0") break;
		if(familyTree.count(persona1) > 0 && familyTree.count(persona2) > 0){
			query(persona1, persona2);
		}else{
			cout << "Persona1: " << persona1 << " or Persona2: " << persona2 << " no existen in DB" << endl; 
		}
		
		// dfs_barrido(persona1);

		// msg("print barrido","");
		// for(auto it = consulta_barrido.begin() ; it != consulta_barrido.end(); it++){
		// 	cout << it->first << "->" << it->second << endl;
		// }
		// dfs_stop(persona2);

		// print consulta_barrido
		// msg("print barrido","");
		// for(auto it = consulta_barrido.begin() ; it != consulta_barrido.end(); it++){
		// 	cout << it->first << "->" << it->second << endl;
		// }
		// printVector grado
		// msg("print vector grado ", "");
		// for(int e = 0 ;e < grado.size() ; e++){
		// 	cout << grado[e] << " " <<  endl;
		// }
	}
	//print familyTree
	// for(auto it = familyTree.begin() ;it != familyTree.end() ; it++){
	// 	cout << it->first << " " << it->second->getSexo()<< endl;
	// }

	//too read file


	// cout << familyTree["Alberto"]->haveParents() << endl;

	
	return 0;
}