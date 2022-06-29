#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

struct Pos{
    int l;
    int c;
    Pos(int l, int c) : l(l), c(c){}
};

std::vector<Pos> pegar_vizinho(Pos p){
    auto [l, c] = p;
    return {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}};
}

void check_entrada (int argc, char *argv[], int &linhas, int &colunas){

    if (argc != 3) {
        std::cout << "Numero de argumentos invalidos\n";
        exit(1);
    }

    std::stringstream(argv[1]) >> linhas;
    std::stringstream(argv[2]) >> colunas;
}

void mostrar_labirinto(std::vector<std::string> labirinto){
    
    for(int i = 0; i < (int) labirinto.size(); i++)
        std::cout << labirinto[i] << "\n";
    //getchar(); Teste
}

bool pode_furar(std::vector<std::string> &labirinto, Pos p){

    auto [l, c] = p;
    int nl = labirinto.size();
    int nc = labirinto[0].size();
    int contador{0};

    for (auto prox : pegar_vizinho(p)) {
        auto [l, c] = prox;
        if(l < 0 || l >= nl || c < 0 || c >= nc) continue;
        if(labirinto[prox.l][prox.c] == '#') contador++;
    }  
    if(contador >= 3) return true;
    return false;
}

std::vector<Pos> misturar(std::vector<Pos> vector){

    std::random_shuffle(begin(vector), end(vector));
    return vector;
}

void criando_labirinto (std::vector<std::string> &labirinto, Pos p){
    
    int nl = labirinto.size();
    int nc = labirinto[0].size();
    auto [l, c] = p;

    if(l < 0 || l >= nl|| c < 0 || c >= nc) return;
    if(labirinto[l][c] != '#') return;
    if(!pode_furar(labirinto, p)) return;

    labirinto[l][c] = ' ';
    //mostrar_labirinto(labirinto); Teste
    for(auto x : misturar(pegar_vizinho(p))){
        criando_labirinto(labirinto, x);
    }
}

void posicao_incial(int &linha, int limite_l, int &coluna, int limite_c){

    linha = 1 + (rand() % (limite_l - 2));
    coluna = 1 + (rand() % (limite_c - 2));
}

int main (int argc, char *argv[]){
    
    srand(time(NULL));
    int linhas{0};
    int colunas{0};
    int l_inicial{0};
    int c_inicial{0};

    check_entrada(argc, argv, linhas, colunas);
    std::vector<std::string> labirinto(linhas, std::string(colunas, '#'));
    posicao_incial(l_inicial, linhas, c_inicial, colunas);
    //mostrar_labirinto(labirinto);
    criando_labirinto(labirinto, Pos(l_inicial, c_inicial));
    mostrar_labirinto(labirinto);

    return 0;
}