#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define msg(str,str2) cout << str << str2<< endl
using namespace std;

class Hora{
	public:
		int m_hora;
		int m_minutos;
	public:
		Hora(string formato){
			//format = formato;
			this->m_hora = stoi(formato.substr(0,2));
			this->m_minutos = stoi(formato.substr(3,2));
		}
		void  getTime(){
			cout << m_hora <<" : "<< m_minutos << endl;
		}

		int getHora(){
			// std::string::size_type sz;
			// return stoi(format.substr(0,2),&sz);
			return m_hora;
		}
		int  getMinutos(){
			// std::string::size_type sz;
			// return stoi(format.substr(3,2),&sz);
			return m_minutos;
		}
		void add(int minutos){
			int hora1 = minutos/60;
			int minutos1 = minutos - 60*hora1;
			// 03:45

			int minutosActual = this->getMinutos() + minutos1;
			int horaActual = this->getHora() + hora1;
			if(minutosActual >= 60){
				minutosActual = minutosActual - 60*(minutosActual/60);
				horaActual +=1;
			}
			if(horaActual >=24){
				horaActual = horaActual%24;
			}

			this->m_hora = horaActual;
			this->m_minutos = minutosActual;
			// this->format = to_string(horaActual) + ":"+ to_string(minutosActual);
			// if(this->format.size() != 5){
			// 	this->format.insert(0,"0");
			// }
		}
};

bool isPalindrome_time(int hora, int minutos){
	// msg("hora: ", hora);
	// msg("minutos", minutos);
	string formato;
	string hora_, minutos_;
	if(hora < 10) hora_ = to_string(0)+ to_string(hora);
	else hora_ = to_string(hora);
	if(minutos < 10 )minutos_ = to_string(0)+ to_string(minutos);
	else  minutos_  = to_string(minutos);
	// msg("hora", hora_);
	// msg("minutos", minutos_);
	// formato = hora_ + minutos_;
	// msg("formato: ", formato);
	// if(minutos < 10) formato = to_string(hora)+ "0" +  to_string(minutos);
	// else formato = to_string(hora) +   to_string(minutos);

	// if(hora < 10) formato = "0" + to_string(hora) +   to_string(minutos);
	formato = hora_ + minutos_;
	// msg("formato: ", formato);
	// msg("formato: ", formato);
	if(formato[0] == formato[3] && formato[1]==formato[2]) return true;
	return false;
}

void solve(){
	// cout << "casko: " << endl;
	string beginTime; cin>>beginTime;
	int x; cin>>x;
	// msg("x is : ", x) ;
	Hora hora(beginTime);
	int cont = 0;
	// for(int e = 0 ; e < 1440/x ; e++){
	// 	// msg("inside for: ",e);
	// 	if(isPalindrome_time(  hora.getHora(), hora.getMinutos()   )) cont++;
	// 	hora.getTime();
	// 	hora.add(x);
	// }
	int horaInicial = stoi(beginTime.substr(0,2));
	int minutosInicial = stoi(beginTime.substr(3,2));
	while(true){
		if(isPalindrome_time(  hora.getHora(), hora.getMinutos()   )) cont++;
		// hora.getTime();
		hora.add(x);
		if(hora.getHora() == horaInicial&& hora.getMinutos() == minutosInicial){
			break;
		}
	}
	cout << cont << endl;
}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	// Hora hora("03:12");
	// // msg(hora.getHora(),"");
	// cout << hora.getTime() << endl;
	// hora.add(360);
	// cout << hora.getTime() << endl;
	// hora.add(360);
	// cout << hora.getTime() << endl;
	// hora.add(360);
	// cout << hora.getTime() << endl;
	// hora.add(360);
	// cout << hora.getTime() << endl;


	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}