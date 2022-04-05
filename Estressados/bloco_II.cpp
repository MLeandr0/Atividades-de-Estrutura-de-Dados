#include <algorithm>
#include <iostream>
#include <vector>

//BLOCO II

//Filter - Operações de Filtragem: 4 funções
std::vector<int> clonar(const std::vector<int>& v){
    std::vector<int> novo{};

    for(int i = 0; i < v.size(); i++){
        novo.push_back(v[i]);
    }

    return novo;
}

std::vector<int> pegar_homens(const std::vector<int>& v){
    std::vector<int> homens{};

    for(int i = 0; i < v.size(); i++){

        if(v[i] > 0) homens.push_back(v[i]);
    }

    return homens;
}

std::vector<int> pegar_calmos(const std::vector<int>& v){
    std::vector<int> calmos{};
    for(int i = 0; i < v.size(); i++){
        if(v[i] < 0){
            if(v[i] * -1 > 0 && v[i] * - 1 < 10) calmos.push_back(v[i]);
        }
        else if(v[i] > 0 && v[i] < 10) calmos.push_back(v[i]);
    }

    return calmos;
}

std::vector<int> pegar_mulheres_calmas(const std::vector<int>& v){
    std::vector<int> mulheres_calmas{};
    for(int i = 0; i < v.size(); i++){
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
    
    for(int i = 0; i < v.size(); i++){
        int existe = 0;
        for(int j = 0; j < new_vector.size(); j++){

            if(new_vector[j] == v[i]) existe = 1;
        }
        if(existe != 1) new_vector.push_back(v[i]);
    }
    return new_vector;
}

std::vector<int> diferentes(const std::vector<int>& v){
    std::vector<int> new_vector{};
     for(int i = 0; i < v.size(); i++){
        int existe = 0;
        for(int j = 0; j < new_vector.size(); j++){

            if(new_vector[j] == v[i] || (-1 * new_vector[j]) == v[i]) existe = 1;
        }
        if(existe != 1) new_vector.push_back(v[i]);
    }

    for(int i = 0; i < new_vector.size(); i++){
        if(new_vector[i] < 0) new_vector[i] *= -1;
    }

    return new_vector;
}

std::vector<int> abandonados(const std::vector<int>& v){

    std::vector<int> final = clonar(v);
    std::vector<int> new_vector = clonar(v);

    int aux = 0;

    for(int i = 0; i < final.size(); i++){
        
        for(int j = 0; j < new_vector.size();){
            aux = 0;
            if(new_vector[j] == final[i]){
                aux = new_vector[j];
                                                      
                for(int y = 0; y < final.size(); y++){
                    if(final[y] == aux){
                        final.erase(final.begin() + y);
                        break;
                    }
                }
                for(int z = 0; z < new_vector.size(); ){
                    if(new_vector[z] == aux){

                        new_vector.erase(new_vector.begin() + z);
                        z = 0;
                    }
                    else z++;  
                }
            }
            else j++;
        }
    }
    return final;  
}

int main(){
    
    //std::vector<int> novo = clonar({-1, 2, 99, 4, -50});
    //std::vector<int> novo = pegar_homens({-1, 2, 99, 4, -50});
    //std::vector<int> novo = pegar_calmos({-99, -9, -10, 99, 9, 10, -5, 5});
    //std::vector<int> novo = pegar_mulheres_calmas({-99, -9, 35, 46, -72, -2, 2});
    //std::vector<int> novo = inverter_com_copia({1, -2, 3, -4, 5, -4});

    //std::cout << sortear({1, 2, 3, 4, 5, 6});
    //{1, 3, 4, 3, -1, -2, -2}
    //std::vector<int> vetor {1, 1, 1, -1, -1, -2, -2, 99, -99, 1, -1, 24, -54, -24, 99};
    //std::vector<int>              1, 1, 1, -1, -1
    //std::vector<int> vetor {1, 3, 4, 3, -1, -2, -2, 2};
    std::vector<int> vetor{73, 21, 37, 12, 7, 3, 42, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1}; //  {3, -2}
    //std::vector<int> novo = exclusivos(vetor);
    //std::vector<int> novo = diferentes(vetor);
    std::vector<int> novo = abandonados(vetor);

    for(int i = 0; i < novo.size(); i++){
       std::cout << novo[i] << " ";
    }

    return 0;
}