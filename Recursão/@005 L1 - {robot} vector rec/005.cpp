#include <sstream>
#include <iostream>
#include <vector>
#include <limits.h>

// Imprimir
void vete(std::vector<int> v, int posicao)
{

    if (posicao == 0)
    {
        std::cout << "[ " << v[posicao] << " ";
        posicao++;
        return vete(v, posicao);
    }
    if (posicao == (int)v.size())
    {
        std::cout << "]"
                  << "\n";
        return;
    }
    std::cout << v[posicao] << " ";
    posicao++;
    vete(v, posicao);
}

// Imprimir ao contrário
void rvet(std::vector<int> v, int posicao)
{

    if (posicao == (int)v.size())
    {
        std::cout << "rvet: [ " << v[posicao - 1] << " ";
        posicao--;
        return rvet(v, posicao);
    }
    if (posicao == 0)
    {
        std::cout << "]"
                  << "\n";
        return;
    }
    std::cout << v[posicao - 1] << " ";
    posicao--;
    rvet(v, posicao);
}

// Imprimir resultado da soma de todo vector
void sum(std::vector<int> v, int posicao, int soma)
{

    if (posicao == (int)v.size())
    {

        std::cout << "sum : " << soma << "\n";
        return;
    }

    soma += v[posicao];
    posicao++;
    sum(v, posicao, soma);
}

// Imprimir o resultado da multiplicação de todo vector
void mult(std::vector<int> v, int posicao, int multiplicacao)
{

    if (posicao == (int)v.size())
    {

        std::cout << "mult: " << multiplicacao << "\n";
        return;
    }

    multiplicacao *= v[posicao];
    posicao++;
    mult(v, posicao, multiplicacao);
}

// Imprimir o mínimo
void min(std::vector<int> v, int posicao, int menor)
{

    if (posicao == (int)v.size())
    {

        std::cout << "min : " << menor << "\n";
        return;
    }

    if (v[posicao] < menor)
        menor = v[posicao];

    posicao++;
    min(v, posicao, menor);
}

// Inverter no lugar
void inv(std::vector<int> &v, int min, int max)
{

    int aux{};

    if (min < max)
    {
        aux = v[min];
        v[min] = v[max];
        v[max] = aux;
        min++;
        max--;

        inv(v, min, max);
    }

    return;
}

int main()
{
    std::string line;
    getline(std::cin, line);
    std::stringstream ss(line);
    std::vector<int> vet;

    int value;
    while (ss >> value)
    {
        vet.push_back(value);
    }

    std::cout << "========\n"
              << "vet : ";
    vete(vet, 0);
    rvet(vet, vet.size());
    sum(vet, 0, 0);
    mult(vet, 0, 1);
    min(vet, 0, INT_MAX);
    inv(vet, 0, vet.size() - 1);
    std::cout << "inv : ";
    vete(vet, 0);
    std::cout << "========\n";

    return 0;
}