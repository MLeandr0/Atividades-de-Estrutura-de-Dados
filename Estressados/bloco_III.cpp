#include <iostream>
#include <vector>

//AUXILIARES

void mostrar(std::vector<int> vetor){

    for(int i = 0; i < (int) vetor.size(); i++){
        std::cout << vetor[i] << " ";
    }
    std::cout << "\n";
}

//BLOCO III
//Map - Manipualção: 3 funções
std::vector<int> sozinhos(const std::vector<int>& v){

    std::vector<int> quantidade(v.size(), 0);
    std::vector<int> unicos{};
    std::vector<int> new_vector = v;

    for(int i = 0; i < (int) v.size(); i++){

        for(int j = 0; j < (int) new_vector.size(); j++){

            if(v[i] == new_vector[j] || (-1 * v[i]) == new_vector[j]) quantidade[i] += 1;
        }
    }

    for(int i = 0; i < (int) quantidade.size(); i++){
        if(quantidade[i] == 1) unicos.push_back(v[i]);
    }

    return unicos;
}

int mais_ocorrencias(const std::vector<int>& v){

    std::vector<int> quantidade(v.size(), 0);
    std::vector<int> aux = v;
    int maior_ocorrencia{};

    for(int i = 0; i < (int) v.size(); i++){

        for(int j = 0; j < (int) aux.size(); j++){

            if(v[i] == aux[j] || (-1 * v[i]) == aux[j]) quantidade[i] += 1;
        }
    }

    for(int i = 0; i < (int) quantidade.size(); i++){
        if(quantidade[i] > maior_ocorrencia) maior_ocorrencia = quantidade[i];
    }

    return maior_ocorrencia;
}

/*Standby
std::vector<int> mais_recorrentes(const std::vector<int>& v){

    std::vector<int> recorrentes{};


    return recorrentes;
}
*/

//Proximidade: 2 funções
int briga(const std::vector<int>& v){

    std::vector<int> ajuda = v;
    int total_brigas{};

    for(int i = 0; i < (int) ajuda.size(); i++){

        if(ajuda[i] < 0) ajuda[i] *= -1;

        if(ajuda[i] > 50 && i != 0 && i != (int) ajuda.size() - 1){
            if(ajuda[i - 1] > 30 && ajuda[i + 1] > 30) total_brigas++;
        }
    }

    return total_brigas;
}

std::vector<int> apaziguados(const std::vector<int>& v){

    std::vector<int> aux = v;
    std::vector<int> apaziguados;

    for(int i = 0; i < (int) aux.size(); i++){

        if(aux[i] < 0) aux[i] *= -1;

        if(aux[i] > 80){
            if(i != 0 && i != (int) aux.size() - 1){
                if(aux[i + 1] < 10 || aux[i - 1] < 10) apaziguados.push_back(i);
            } 
            else if(i != 0 && i == (int) aux.size() - 1){
                if(aux[i - 1] < 10) apaziguados.push_back(i); 
            }
            if(aux[i + 1] < 10) apaziguados.push_back(i); 
        }  
    }
    return apaziguados;
}

//Sequências: 3 funções
int quantos_times(const std::vector<int>& v){
    
    int quantidade_times{};
    int contador_homens{};
    int contador_mulheres{};

    for(int i = 0; i < (int) v.size(); i++){
        
        if(v[i] > 0){
            contador_homens++;
            if(contador_mulheres > 1) {
                quantidade_times++;
            }
            contador_mulheres = 0;
            
        }
        if(v[i] < 0){
            if(contador_homens > 1){
                quantidade_times++;
            }
            contador_mulheres++;
            contador_homens = 0;
        }
        if(i == (int) v.size() - 1){
            if(contador_homens > 1 || contador_mulheres > 1) {
                quantidade_times++;
                break;
            }
        }
    }
    return quantidade_times;
}

//Falhando
std::vector<int> maior_time(const std::vector<int>& v){

    std::vector<int> maior_time{};
    int tamanho{};

    for(int i = 0; i < (int) v.size(); i++){

        if(v[i] > 0){ //HOMENS
            if(maior_time[0] < 0) {
                maior_time.clear();
                tamanho = 0;
            }
            maior_time.push_back(v[i]);
            tamanho += maior_time[i];

        }
        if(v[i] < 0){ //MULHERES
            if(maior_time[0] > 0) {
                maior_time.clear();
                tamanho = 0;
            }
            maior_time.push_back(v[i]);
            tamanho = tamanho + (maior_time[i] * -1);
            
        }
    }


    return maior_time;
}

int sem_time(std::vector<int> vet){

    int sem_time{};
    int aux_H{};
    int aux_M{};

    for(int i = 0; i < (int) vet.size(); i++){

        if(vet[i] > 0){
                
            aux_H++;
            if(aux_M == 1){
                sem_time++;
            }
            aux_M = 0;
        }
        else{
            aux_M++;
            if(aux_H == 1){
                sem_time++;
            }
            aux_H = 0;
        }
    }

    return sem_time;
}

//GRUPOS: 2 funções
int casais(std::vector<int> v){

    int quantidade_casais{};

    for(int i = 0; i < (int) v.size(); ){

        if(i != (int) v.size() - 1){
            if(v[i] == (v[i + 1] * -1) || (v[i] * -1) == v[i + 1]){
                quantidade_casais++;
                v.erase(v.begin() + i);
                v.erase(v.begin() + i);
            }
            else i++;
        }
        else i++;
        
    }
    
    return quantidade_casais;
}

//int trios(){}

//Alteração: 3 funções;
//vector remover(){}
//vector insert(){}
//vector dance(){}



int main(){

    std::vector<int> novo{};

    //novo = sozinhos({1, 1, 2, 3, 3, 4});
    //novo = sozinhos({1, 3, 4, 3, -1, -3, -3});
    //novo = apaziguados({83, -4, 65, 8, -99, 12 });
    //novo = maior_time({-5, 3, -1, 15, 1, -99, 11, 1 });
    //int quantidade = sem_time({-5, 3, 1, 15, -1, -99, -11, -1, -7});
    int quantidade = casais({1, -1, -2, 2, 3, -3, 5, 4, 4, -3, 2, 5, -5, 1, -1, 2, -2, 2, -2, 3, 2, 4, -3, 3, 3, 3});

                            // * * * * *
    //int resultado = briga({50, 98, 31, -51, 31, -99});
    //td::vector<int>  novo { 1, -1, 1, -1, 2, -2, 3, 4, -3, -4};
    //int quantidade = quantos_times({5, 3, 1, -11, 1, 99, -11, -1, -2, 44});

    //mostrar(resposta);
    //mostrar(novo);
    //std::cout << resultado << "\n";
    std::cout << quantidade << "\n";

    //std::cout << mais_ocorrencias({1, 3, 4, 5, -1, -5, -5}) << "\n";
    //std::cout << mais_ocorrencias({1, 1, 1, 1, 2, 2, 2, -4, -4, -4, 4, -4}) << "\n";

    return 0;
}