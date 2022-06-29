#include <iostream>
#include <unordered_map>

// Conta quantas palavras foram encontradas
void contador(std::unordered_map<std::string, int> &check, std::string *vetor, int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    {

        std::string aux = vetor[i];
        if (check.find(aux) != check.end())
            check[aux] += 1;
    }
}

int main()
{

    // Recebe a primeira lista de palavas
    int n{0};
    std::cin >> n;
    std::cin.ignore();
    std::string vetor[n];

    for (int i = 0; i < n; i++)
    {
        std::string aux{0};
        std::cin >> aux;
        vetor[i] = aux;
    }

    // Recebe a segunda
    int n2{0};
    std::cin >> n2;
    std::cin.ignore();
    std::unordered_map<std::string, int> check;

    std::string auxiliar_imprimir[n2];

    for (int j = 0; j < n2; j++)
    {
        std::string aux_string;
        std::cin >> aux_string;
        auxiliar_imprimir[j] = aux_string;
        check[aux_string] = 0;
    }

    contador(check, vetor, n);

    // Imprime a quantia encontrada,
    int vetor_final[n2];
    for (int i = 0; i < n2; i++)
    {
        vetor_final[i] = check[auxiliar_imprimir[i]];
        std::cout << vetor_final[i] << " ";
    }
    std::cout << std::endl;
}