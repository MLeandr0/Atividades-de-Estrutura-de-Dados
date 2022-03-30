#include <iostream>
#include <list>

void mostrar_matanca(std::list<int> list, int posicao)
{
    if (posicao > list.size())
        posicao = 0;
    else
        posicao -= 1;
    int contador_auxiliar = 0;
    std::cout << "[ ";

    for (auto i : list)
    {

        std::cout << i;
        if (contador_auxiliar == posicao)
        {

            std::cout << "> ";
        }
        else
            std::cout << " ";
        contador_auxiliar++;
    }

    std::cout << "]" << std::endl;
}

void matar(std::list<int> &list, int &posicao)
{

    int tamanho = list.size();

    if (tamanho == posicao)
    {

        posicao = 0;
        list.erase(std::next(list.begin(), posicao));
    }

    else if (tamanho < posicao)
    {
        posicao = 1;
        list.erase(std::next(list.begin(), posicao));
    }

    else
    {

        list.erase(std::next(list.begin(), posicao));
    }
    posicao++;
}

int main()
{

    int N{}, E{};
    std::list<int> elementos{};
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