#include <iostream>
#include <stack>
#include <list>
#include <vector>


void show(std::vector<std::string> mat)
{
    for (int i = 0; i < (int)mat.size(); i++)
    {
        std::cout << mat[i] << "\n";
    }

}

std::list<std::pair<int,int>> encontrar_vizinho(std::vector<std::string> matriz, std::pair<int,int> coordenadas, int nl, int nc){

    std::list<std::pair<int,int>> lista;
    
    if(coordenadas.first >= 0 && coordenadas.first < nl - 1){

        if(matriz[coordenadas.first + 1][coordenadas.second] == '#'){
            lista.push_back({coordenadas.first + 1, coordenadas.second});
        }
    }

    if(coordenadas.second < nc - 1 && coordenadas.second >= 0){
        if(matriz[coordenadas.first][coordenadas.second + 1] == '#'){
            lista.push_back({coordenadas.first, coordenadas.second + 1});
        }
    }
    
    if(coordenadas.first != 0 && coordenadas.first < nl){
        if(matriz[coordenadas.first - 1][coordenadas.second] == '#' ){
            lista.push_back({coordenadas.first - 1, coordenadas.second});
        }
    }
    
    
    if(coordenadas.second != 0 && coordenadas.second < nc){
        if(matriz[coordenadas.first][coordenadas.second - 1] == '#'){
            lista.push_back({coordenadas.first, coordenadas.second - 1});
        }

    }
    return lista;
}

void queimada(std::vector<std::string> &matriz, std::pair<int,int> coordenadas, int nl, int nc){

    std::list<std::pair<int,int>> lista_aux;
    std::stack<std::pair<int,int>> pilha;
    if(matriz[coordenadas.first][coordenadas.second] == '#'){
        matriz[coordenadas.first][coordenadas.second] = 'o';
        pilha.push(coordenadas);
    }
    while(!pilha.empty()){

        lista_aux = encontrar_vizinho(matriz, pilha.top(), nl, nc);

        if(lista_aux.empty()){
            pilha.pop();
        }
        else{
            matriz[lista_aux.back().first][lista_aux.back().second] = 'o';
            pilha.push({lista_aux.back().first, lista_aux.back().second});
        }

    }
}

int main(){

    int nl{}, nc{};
    std::pair<int,int> coordenadas;
    scanf("%d %d %d %d\n", &nl, &nc, &coordenadas.first, &coordenadas.second);
    std::vector<std::string> mat;

    for (int i = 0; i < nl; i++)
    {
        std::string line;
        std::cin >> line;
        mat.push_back(line);
    }
    
    queimada(mat, coordenadas, nl, nc);
    show(mat);


    return 0;
}