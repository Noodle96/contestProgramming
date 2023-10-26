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

int gcd(int a,int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

/*
	Data Structure: Trie
*/
class NodeTrie{
public:
    map<char,NodeTrie*> children;
    bool endOfWord;
    string valueState ;
public:
    NodeTrie(){
        this->endOfWord = false;
        this->valueState="R"; // any valor
    }
    bool isEndOfWord(){return this->endOfWord;}
    void setValueState(std::string value){this->valueState =value;}
    string getValueState()const{return valueState;}
};

class Trie{
public:
    NodeTrie *m_pRoot;
    int m_height;
public:
    Trie(){
        m_pRoot = new NodeTrie();
        //m_height =1;
    }
    ~Trie(){delete m_pRoot;}

    int getHeight(){return m_height;}

    /**
    * Iterative implementation of insert into trie
    */
    void insert(string word){
		NodeTrie *current = &(*m_pRoot);
		for (int i = 0; i < word.length(); i++){
			char ch = word[i];
			NodeTrie *node = current->children[ch];
			// if(!node){
			//     std::cout << "any" << std::endl;
			// }
			// std::cout << node->isEndOfWord() << std::endl;
			if (!node) {
				//INCREMENT NUMBER NODES
				//m_height ++;
				node = new NodeTrie();
				current->children[ch] = node;
				if(current==m_pRoot){
					string valueStateTemp = "";
					valueStateTemp.push_back(ch);
					node->setValueState(valueStateTemp);
				}else{
					string valueStateTemp = current->getValueState();
					valueStateTemp.push_back(ch);
					node->setValueState(valueStateTemp);
				}
			}
			current = node;
		}
		//mark the current nodes endOfWord as true
		current->endOfWord = true;
		current->setValueState(word);
	}
    bool search(string word){
		NodeTrie *current = m_pRoot;
		for (int i = 0; i < word.length(); i++) {
			char ch = word[i];
			NodeTrie *node = current->children[ch];
			//if node does not exist for given char then return false
			if (!node) {
				return false;
			}
			current = node;
		}
		//return true of current's endOfWord is true else return false.
		return current->isEndOfWord();
	}
};


void solve(){
	Trie *trie = new Trie();
	trie->insert("abc");
	trie->insert("abcd");
	trie->insert("mono");
	trie->insert("mon");
	string q; 
	while(1){
		cin>>q;
		cout << trie->search(q) << endl;
	}
	delete trie;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}