#include <iostream>
#include <unordered_map>

int main()
{

    int tamanho{0}, rotacao{0};
    std::cin >> tamanho >> rotacao;
    int vetor[tamanho];
    std::unordered_map<int, int> auxiliar;

    for (int i = 0; i < tamanho; i++)
    {
        int aux{0};
        std::cin >> aux;
        vetor[i] = aux;
    }

    if (rotacao > tamanho)
        rotacao = rotacao % tamanho;
    for (int i = 0, j = 0; i < tamanho; i++)
    {

        if (i + rotacao >= tamanho)
        {
            auxiliar[j] = vetor[i];
            j++;
        }
        else
            auxiliar[i + rotacao] = vetor[i];
    }

    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = auxiliar[i];
    }

    for (int i = 0; i < tamanho; i++)
    {
        std::cout << vetor[i] << " ";
    }
    std::cout << "\n";
    return 0;
}