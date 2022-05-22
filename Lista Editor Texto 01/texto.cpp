#include <iostream>
#include <list>

void enter(std::list<char> &texto, std::list<char>::iterator &it){
    texto.insert(it, '\n');
}

void backspace(std::list<char> &texto, std::list<char>::iterator &it){
    if(it != texto.begin()){
        it--;
        it = texto.erase(it);
    }
}

void backspace_delete(std::list<char> &texto, std::list<char>::iterator &it){
    if(it != texto.end()) it = texto.erase(it);
}

void retornar(std::list<char> &texto, std::list<char>::iterator &it){
    if(it != texto.begin()) it--;
}

void seguir(std::list<char> &texto, std::list<char>::iterator &it){
    if(it != texto.end()) it++;
}

void check(std::list<char> &entrada, std::list<char> &texto){

    std::list<char>::iterator it = texto.begin();

    for(auto x : entrada){

        if(x == 'R'){
            enter(texto, it);
        }
        else if(x == 'B'){
            backspace(texto, it);
        }
        else if(x == 'D'){
            backspace_delete(texto, it);
        }
        else if(x == '<'){
            retornar(texto, it);
        }
        else if(x == '>'){
            seguir(texto, it);
        }
        else texto.insert(it, x);
    }
    texto.insert(it, '|');
}

int main(){

    std::string palavra;
    std::list<char> entrada;
    std::list<char> texto;
    getline(std::cin, palavra);

    for(int i = 0; i < palavra.size(); i++){
        entrada.push_back(palavra[i]);
    }
    check(entrada, texto);

    for(auto x : texto) std::cout << x;
    std::cout << "\n";

    return 0;
}