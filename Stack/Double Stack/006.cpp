#include <iostream>
#include <stack>

void remover(std::stack<int> &fila){

    std::stack<int>fila_aux;
    while(!fila.empty()){
        if(fila.size() != 1){
            fila_aux.push(fila.top()); 
        }
        fila.pop();
    }

    while(!fila_aux.empty()){
        fila.push(fila_aux.top()); 
        fila_aux.pop();
    }
}

void comeco(std::stack<int> fila, std::stack<int> &resultado){

    while(!fila.empty()){
        if(fila.size() == 1){
            resultado.push(fila.top());
        }
        fila.pop();
    }
}

int main(){

    int n_consultas{};
    std::stack<int> deposito;
    std::stack<int> prateleira;
    std::cin >> n_consultas;

    for(int i = 0; i < n_consultas; i++){
        int aux {};
        std::cin >> aux;
        if (aux == 1){
            std::cin >> aux;
            deposito.push(aux);
        }
        else if (aux == 2){
            remover(deposito);
        }
        else if (aux == 3){
            comeco(deposito, prateleira);
            std::cout << prateleira.top() << "\n";
        }
    }

    return 0;
}