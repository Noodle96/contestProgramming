#include <iostream>
#include <unordered_map>

int problemas_resueltos(std::unordered_map<char, int>& diccionario, const std::string& cadena) {
    for (char character : cadena) {
        diccionario[character] -= 1;
    }
    int count = 0;
    for (const auto& pair : diccionario) {
        if (pair.second <= 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        std::unordered_map<char, int> diccionario;
        for (int j = 0; j < 26; ++j) {
            diccionario['A' + j] = j + 1;
        }
        std::string cadena;
        std::cin >> cadena;
        int resultado = problemas_resueltos(diccionario, cadena);
        std::cout << resultado << std::endl;
    }
    return 0;
}