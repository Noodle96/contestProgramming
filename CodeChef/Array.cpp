#include <iostream>
#include <unordered_map>
#include <set>
#include <cstdlib>
using namespace std;
using LI = long int;
using UM_LI = unordered_map<LI,LI> ;
using S_LI = set<LI>;

using UMm_LI = unordered_multimap<LI,LI>;

UMm_LI newArray( UMm_LI &dataEstructure){
    LI valorTemp = 1;
    UMm_LI newDataEstructure;
    newDataEstructure.insert(make_pair<LI,LI>(1,rand() % 100 + 1000000000));
    auto before = dataEstructure.begin();
    auto current = ++dataEstructure.begin();
    for(; current != dataEstructure.end(); current++){
        valorTemp = (before->first + current->first);
        newDataEstructure.insert(make_pair<LI,LI>(before->first + current->first,rand() % 100 + 1000000000));
        before = current;
    }
    newDataEstructure.insert(make_pair<LI,LI>(1,rand() % 100 + 1000000000));
    return newDataEstructure;
}


void printUM_LI(UM_LI &umap){
    for(auto e = umap.begin() ; e!= umap.end(); e++){
        cout << e->first<< " " << e->second << endl;
    }
}
void printSET_LI(S_LI &setO){
    for(auto e = setO.begin() ; e!= setO.end(); e++){
        cout << *e << " ";
    }
    cout << endl;
}
void printUMm_LI(UMm_LI &dataEst){
    for(auto e = dataEst.begin() ; e!= dataEst.end(); e++){
        cout << e->first<< " " << e->second << endl;
    }
}

int main(){
    UMm_LI dataes;
    dataes.insert(make_pair<LI,LI>(1,rand() % 100 + 1000000000));
    dataes.insert(make_pair<LI,LI>(1,rand() % 100 + 1000000000));

    dataes = newArray(dataes);

    printUMm_LI(dataes);

    return 0;
}