#include <iostream>
#include <vector>

int mostrar_matanca(std::vector<int> vector, int tamanho, int posicao)
{

    std::cout << "[ ";
    for (int i = 0; i < tamanho; i++)
    {

        if (vector.at(i) != 0)
        {
            if (i == posicao)
            {
                std::cout << vector[i] << "> ";
            }
            else
                std::cout << vector[i] << " ";
        }
    }

    std::cout << "]" << std::endl;
}

int mao_espada(int tamanho, int posicao)
{

    int i = (1 + posicao) % tamanho;

    return i;
}

int alvo(std::vector<int> &vector, int tamanho, int posicao)
{
    while (vector[mao_espada(tamanho, posicao)] == 0)
    {

        posicao = mao_espada(tamanho, posicao);
    }

    return posicao;
}

void matar(std::vector<int> &vector, int tamanho, int &posicao)
{

    int matar = alvo(vector, tamanho, posicao);

    vector.at(mao_espada(tamanho, matar)) = 0;
    matar = alvo(vector, tamanho, matar);
    posicao = mao_espada(tamanho, matar);
}

int main()
{

    int N{}, E{};
    std::vector<int> elementos{};
    std::cin >> N >> E;
    E -= 1;

    for (int i = 1; i <= N; i++)
    {

        elementos.push_back(i);
    }

    int copy_N = N;
    mostrar_matanca(elementos, N, E);

    while (copy_N > 1)
    {
        matar(elementos, N, E);
        mostrar_matanca(elementos, N, E);
        copy_N--;
    }

    return 0;
}