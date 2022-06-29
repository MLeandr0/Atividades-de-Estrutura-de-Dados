#include <iostream>
#include <unordered_set>

int main()
{

    int tamanho{0};
    int quantidade{0};
    std::cin >> tamanho;
    std::unordered_set<int> fila;
    int vetor_aux[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        int aux{0};
        std::cin >> aux;
        vetor_aux[i] = aux;
        fila.insert(aux);
    }

    std::cin >> quantidade;
    int vetor[quantidade];
    int vetor_ordenado[tamanho - quantidade];
    for (int i = 0; i < quantidade; i++)
    {
        int aux{0};
        std::cin >> aux;
        vetor[i] = aux;
    }

    for (int i = 0; i < quantidade; i++)
    {
        fila.erase(vetor[i]);
    }

    for (int i = 0, j = 0; i < tamanho; i++)
    {
        if (fila.find(vetor_aux[i]) != fila.end())
        {
            vetor_ordenado[j] = vetor_aux[i];
            j++;
        }
    }

    for (int i = 0; i < (tamanho - quantidade); i++)
    {
        std::cout << vetor_ordenado[i] << " ";
    }
    std::cout << "\n";

    return 0;
}