#include <algorithm>
#include <iostream>
#include <vector>

//BLOCO II

//Filter - Operações de Filtragem: 4 funções
std::vector<int> clonar(const std::vector<int>& v){
    std::vector<int> novo{};

    for(int i = 0; i < (int) v.size(); i++){
        novo.push_back(v[i]);
    }

    return novo;
}

std::vector<int> pegar_homens(const std::vector<int>& v){
    std::vector<int> homens{};

    for(int i = 0; i < (int) v.size(); i++){

        if(v[i] > 0) homens.push_back(v[i]);
    }

    return homens;
}

std::vector<int> pegar_calmos(const std::vector<int>& v){
    std::vector<int> calmos{};
    for(int i = 0; i < (int) v.size(); i++){
        if(v[i] < 0){
            if(v[i] * -1 > 0 && v[i] * - 1 < 10) calmos.push_back(v[i]);
        }
        else if(v[i] > 0 && v[i] < 10) calmos.push_back(v[i]);
    }

    return calmos;
}

std::vector<int> pegar_mulheres_calmas(const std::vector<int>& v){
    std::vector<int> mulheres_calmas{};
    for(int i = 0; i < (int) v.size(); i++){
        if(v[i] < 0){
            if(v[i] * -1 > 0 && v[i] * - 1 < 10) mulheres_calmas.push_back(v[i]);
        }
    }

    return mulheres_calmas;
}

//Acesso: 5 funções
std::vector<int> inverter_com_copia(const std::vector<int>& v){
    std::vector<int> invertido{};
    for(int i = v.size() - 1; i >= 0; i--){
        invertido.push_back(v[i]);
    }
    
    return invertido;
}

void inverter_inplace(std::vector<int>& v){
    
    reverse(v.begin(), v.end());
}

int sortear(const std::vector<int>& v){
    srand(time(NULL));
    int number = v[rand() % v.size()];

    return number;
}

void embaralhar(std::vector<int>& v){
    
    std::random_shuffle(v.begin(), v.end());
}

void ordenar(std::vector<int>& v){
    
    sort(v.begin(), v.end());
}

//Conjuntos: 3 funções
std::vector<int> exclusivos(const std::vector<int>& v){

    std::vector<int> new_vector{};
    
    for(int i = 0; i < (int) v.size(); i++){
        int existe = 0;
        for(int j = 0; j < (int) new_vector.size(); j++){

            if(new_vector[j] == v[i]) existe = 1;
        }
        if(existe != 1) new_vector.push_back(v[i]);
    }
    return new_vector;
}

std::vector<int> diferentes(const std::vector<int>& v){
    std::vector<int> new_vector{};
     for(int i = 0; i < (int) v.size(); i++){
        int existe = 0;
        for(int j = 0; j < (int) new_vector.size(); j++){

            if(new_vector[j] == v[i] || (-1 * new_vector[j]) == v[i]) existe = 1;
        }
        if(existe != 1) new_vector.push_back(v[i]);
    }

    for(int i = 0; i < (int) new_vector.size(); i++){
        if(new_vector[i] < 0) new_vector[i] *= -1;
    }

    return new_vector;
}

std::vector<int> abandonados(const std::vector<int>& v){
    
    std::vector<int> abandonados {};
    std::vector<int> exclusivo {};
    
    for(int i = 0; i < (int) v.size(); i++){
        int existe = 0;
        for(int j = 0; j < (int) exclusivo.size(); j++){

            if(exclusivo[j] == v[i]) existe = 1;
        }
        if(existe != 1) exclusivo.push_back(v[i]);
        else abandonados.push_back(v[i]);
    }

    return abandonados;
}

//Auxiliar
void mostrar(std::vector<int> vetor){

    for(int i = 0; i < vetor.size(); i++){
        std::cout << vetor[i] << " ";
    }
    std::cout << "\n";
}

int main(){
    
    //std::vector<int> vetor{6, 5, 4, 3, 2, 1};
    //std::vector<int> novo{}; 

    //Operações de Filtagrem
    //novo = clonar({-1, 2, 99, 4, -50});
    //novo = pegar_homens({-1, 2, 99, 4, -50});
    //novo = pegar_calmos({-99, -9, -10, 99, 9, 10, -5, 5});
    //novo = pegar_mulheres_calmas({-99, -9, 35, 46, -72, -2, 2});


    //Acesso: 5 funções
    //novo = inverter_com_copia({-4, -2, 1, 3, 5});
    //inverter_inplace(vetor);
    //std::cout << sortear(vetor);
    //embaralhar(vetor);
    //ordenar(vetor);

    //Conjuntos: 3 funções
    //novo = exclusivos({1, 3, 4, 3, -1, -2, -2});
    //novo = diferentes({1, 3, 4, 3, -1, -2, -2});
    //novo = abandonados({1, 3, 4, 3, -1, -2, -2});

    //mostrar(vetor);
    //mostrar(novo);

    return 0;
}