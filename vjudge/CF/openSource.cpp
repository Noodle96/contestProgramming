#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define msg(str,str2) cout << str << str2<< endl
using namespace std;
// bool sortbyCond(const pair<int, int>& a,
//                 const pair<int, int>& b)
// {
//     if (a.first != b.first)
//         return (a.first < b.first);
//     else
//        return (a.second > b.second);
// }
bool sortbyCond(const pair<int, string>& a,
                const pair<int, string>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
}
void solve2(string line){
	map<string, set<string> > grupo_student;
	map<string, string > student_grupo;
	set<string> gruposNamesWihoutStudents;
	string grupo;
	string temporal_grupo;
	while(line[0] != '1'){
		if(line[0] >= 65 && line[0] <= 90){ //MAYUSCULA
			grupo = line;
			gruposNamesWihoutStudents.insert(grupo);
		}else{			
			if(student_grupo.count(line) > 0){ // alumno inscrito en otro grupo
				temporal_grupo= student_grupo[line];
				if(temporal_grupo !=grupo){// eliminamos inscripcion del otro curso
					grupo_student[temporal_grupo].erase(line);
				}
			}else{ // alumno no inscrito en ningun curso
				student_grupo[line] = grupo;
				grupo_student[grupo].insert(line);
			}
			//quitar  grupo de  gruposNamesWihoutStudents
			if(grupo_student.count(grupo) >  0){
				gruposNamesWihoutStudents.erase(grupo);
			}
		}

		std::getline(std::cin, line);
	}
	//processing output
	vector<pair<int,string>> ordered_data;
	for(auto it = grupo_student.begin(); it != grupo_student.end() ; it++){
		ordered_data.push_back(make_pair(it->second.size(), it->first));
	}
	for(auto it = gruposNamesWihoutStudents.begin(); it != gruposNamesWihoutStudents.end() ; it++){
		ordered_data.push_back(make_pair(0,*it));
	}
	// for(auto it = ordered_data.begin(); it != ordered_data.end() ; it++){
	// 	cout << it->first << " " << it->second << endl;
	// }
	sort(all(ordered_data),sortbyCond);
	for(auto it = ordered_data.rbegin(); it != ordered_data.rend() ; it++){
		cout << it->second << " " << it->first << endl;
	}
}

void solve(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	string line;
	std::getline(std::cin,line);
	while(line[0] != '0'){
		solve2(line);
		std::getline(std::cin,line);
	}

}

int main(){
	solve();
	return 0;
}