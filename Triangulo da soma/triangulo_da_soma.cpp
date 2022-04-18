#include <iostream>
#include <sstream>
#include <vector>

// Mostrar um vetor
void show(std::vector<int> vector)
{

    std::cout << "[ ";
    for (auto n : vector)
    {
        std::cout << n << " ";
    }
    std::cout << "]" << std::endl;
}

// Fazer a soma para criar um vetor novo
std::vector<int> somar(std::vector<int> vetor)
{
    std::vector<int> novo{};

    for (int i = 0; i < (int)vetor.size(); i++)
    {

        if (i != (int)vetor.size() - 1)
        {
            novo.push_back(vetor[i] + vetor[i + 1]);
        }
    }

    return novo;
}

// Imprimir na ordem correta
void juntando_tudo(std::vector<int> vector)
{

    std::vector<int> aux = somar(vector);

    if (aux.size() == 1)
        return show(aux);

    juntando_tudo(aux);
    show(aux);
}

int main()
{

    std::string linha{};
    getline(std::cin, linha);
    std::stringstream ss(linha);
    std::vector<int> vetor{};
    int value{0};
    while (ss >> value)
        vetor.push_back(value);

    std::vector<int> resultado = somar(vetor);
    juntando_tudo(vetor);
    show(vetor);

    return 0;
}