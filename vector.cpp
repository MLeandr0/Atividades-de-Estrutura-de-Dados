#include <iostream>
#include <vector>

void mostrar_matanca(std::vector<int> &vector, int posicao)
{

    int tamanho = vector.size();

    if (posicao > tamanho)
        posicao = 0;
    else if (posicao != 0)
        posicao -= 1;

    std::cout << "[ ";
    for (int i = 0; i < tamanho; i++)
    {

        if (i == posicao)
            std::cout << vector[i] << "> ";
        else
            std::cout << vector[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void matar(std::vector<int> &vector, int &posicao)
{

    int tamanho = vector.size();

    if (tamanho == posicao)
    {

        posicao = 0;
        vector.erase(vector.begin() + posicao);
    }

    else if (tamanho < posicao)
    {
        posicao = 1;
        vector.erase(vector.begin() + posicao);
    }

    else
    {

        vector.erase(vector.begin() + posicao);
    }
    posicao++;
}

int main()
{

    int N{}, E{};
    std::vector<int> elementos{};
    std::cin >> N >> E;

    for (int i = 1; i <= N; i++)
    {

        elementos.push_back(i);
    }

    mostrar_matanca(elementos, E);
    do
    {

        matar(elementos, E);
        mostrar_matanca(elementos, E);
        N--;

    } while (N > 1);

    return 0;
}