#include <iostream>
#include <list>

bool eh_negativo(std::list<int>::iterator fila){
    return *fila < 0;
}

void toString(std::list<int> &fila, std::list<int>::iterator posicao){
    std::cout << "[ ";
    
    std::list<int>::iterator it;
    for(it = fila.begin(); it != fila.end(); it++){
        if(it == posicao){
            if(*it < 0) std::cout << "<" << *it << " ";
            else std::cout << *it << "> ";
        }
        else std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

std::list<int>::iterator proxima_posicao(std::list<int>::iterator posicao, std::list<int> &fila){
    
    bool tipo = eh_negativo(posicao);
    if(!tipo){
        if(posicao == --fila.end()) return fila.begin();;
        return ++posicao;
    }
    else{
        if(posicao == fila.begin()) return --fila.end();
        return --posicao;
    }

}

std::list<int>::iterator matar(std::list<int>::iterator posicao, std::list<int> &fila){

    std::list<int>::iterator facada = proxima_posicao(posicao, fila);
    fila.erase(facada);
    return proxima_posicao(posicao, fila);

}

int main(){

    int tamanho{0}, posicao{0}, tipo{0};
    std::cin >> tamanho >> posicao >> tipo;
    std::list<int> fila{};

    //Creation
    for(int i = 0; i < tamanho; i++){

        if(tipo < 0 && i % 2 == 0) fila.push_back((i + 1) * -1);
        else if(tipo > 0 && i % 2 != 0) fila.push_back((i + 1) * -1);
        else fila.push_back(i + 1);
    }

    /*Print test 
    std::cout << "FILA = ";
    for(auto x : fila) std::cout << x << " ";
    std::cout << "\n";*/

    //True Position
    posicao -= 1;
    std::list<int>::iterator new_posicao = fila.begin();
    for(int i = 0; i < posicao; i++, new_posicao++);

    toString(fila, new_posicao);
    while(fila.size() != 1){ 
    
        new_posicao = matar(new_posicao, fila);
        toString(fila, new_posicao);
    } 

    return 0;
}