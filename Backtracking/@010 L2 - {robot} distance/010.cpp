#include <iostream>
#include <algorithm>

bool pode_inserir(std::string lista, int proximidade, int N, int index)
{

    // Indo pra frente
    for (int i = index + 1; i < index + 1 + proximidade; i++)
    {
        if (i < (int)lista.size() && lista[i] == N + '0')
            return false;
    }
    // Voltando
    for (int i = index - proximidade; i < index; i++)
    {
        if (i >= 0 && lista[i] == N + '0')
            return false;
    }

    return true;
}

bool checagem(std::string &lista, int proximidade, int &N, int index)
{

    if ((int)lista.size() == index)
    {

        // std::cout << lista << " check" << '\n'; //Usado pra teste
        return true;
    }

    if (lista[index] != '.')
        return checagem(lista, proximidade, N, index + 1);

    for (int i = 0; i <= N; i++)
    {
        if (pode_inserir(lista, proximidade, i, index))
        {
            // std::cout << lista << "\n"; //Usado pra teste
            lista[index] = i + '0';
            if (checagem(lista, proximidade, N, index + 1))
                return true;
        }
    }
    lista[index] = '.';
    // std::cout << lista << '\n'; //Usado pra teste
    return false;
}

int main()
{

    std::string lista{0};
    int proximidade{0};
    getline(std::cin, lista);
    std::cin >> proximidade;
    int N = 0;

    while (!checagem(lista, proximidade, N, 0))
        N++;

    std::cout << "========\n"
              << N << "\n"
              << "<<<<<<<<\n";

    return 0;
}