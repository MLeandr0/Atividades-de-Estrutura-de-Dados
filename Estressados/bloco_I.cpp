#include <iostream>
#include <vector>

// BOLCO I

// Busca: 4 funções;
bool existe(std::vector<int> fila, int x)
{

    for (int i = 0; i < fila.size(); i++)
    {
        if (fila[i] == x)
            return true;
    }

    return false;
}

int contar(std::vector<int> fila, int x)
{
    int contador = 0;
    for (int i = 0; i < fila.size(); i++)
    {
        if (fila[i] == x)
            contador++;
    }

    return contador;
}

int procurar(std::vector<int> fila, int x)
{
    for (int i = 0; i < fila.size(); i++)
    {
        if (fila[i] == x)
            return 1;
    }
    return -1;
}

int procurar_valor(std::vector<int> fila, int x, int inicio)
{

    for (int i = inicio; i < fila.size(); i++)
    {
        if (fila[i] == x)
            return i;
    }
    return -1;
}

// Melhor caso: 4 funções;
int procurar_menor(std::vector<int> fila)
{

    int aux = 99;
    for (int i = 0; i < fila.size(); i++)
    {
        if (fila[i] < aux)
            aux = fila[i];
    }
    return aux;
}

int procurar_pos_menor(std::vector<int> fila)
{

    int posicao = procurar_menor(fila);
    for (int i = 0; i < fila.size(); i++)
    {
        if (fila[i] == posicao)
            return i;
    }

    return 0;
}

int procurar_pos_menor_apartir(std::vector<int> fila, int inicio)
{
    int aux = 99;
    int indice = 0;
    for (int i = inicio; i < fila.size(); i++)
    {
        if (fila[i] < aux)
        {
            aux = fila[i];
            indice = i;
        }
    }
    return indice;
}

int procurar_melhor_pos_se(std::vector<int> fila)
{
    int aux = 99;
    int indice = -1;

    for (int i = 0; i < fila.size(); i++)
    {
        if (fila[i] > 0 && fila[i] < aux)
        {
            aux = fila[i];
            indice = i;
        }
    }
    return indice;
}

// Contagem: 4 funções;
float calcular_estress_medio(std::vector<int> fila)
{

    float total = 0;
    for (int i = 0; i < fila.size(); i++)
    {
        if (fila[i] < 0)
            total += (fila[i] * -1);
        else
            total += fila[i];
    }

    total /= fila.size();
    return total;
}

std::string mais_homens_ou_mulheres(std::vector<int> fila)
{
    int contador_h = 0;
    int contador_m = 0;
    for (int i = 0; i < fila.size(); i++)
    {
        if (fila[i] > 0)
            contador_h++;
        else
            contador_m++;
    }
    if (contador_h > contador_m)
        return "homens";
    else if (contador_h == contador_m)
        return "empate";
    else
        return "mulheres";
}

std::string qual_metade_eh_mais_estressada(std::vector<int> fila)
{
    int metade = fila.size() / 2;
    int comeco = 0;
    int final = 0;

    for (int i = 0; i < metade; i++)
    {
        if (fila[i] < 0)
            comeco += (fila[i] * -1);
        else
            comeco += fila[i];
    }
    for (int i = metade; i < fila.size(); i++)
    {
        if (fila[i] < 0)
            final += (fila[i] * -1);
        else
            comeco += fila[i];
    }
    if (comeco > final)
        return "primeira";
    else if (comeco == final)
        return "empate";
    else
        return "segunda";
}

std::string quem_eh_mais_estressado(std::vector<int> fila)
{
    float contador_men = 0;
    int indice_women = 0;
    float contador_women = 0;

    for (int i = 0; i < fila.size(); i++)
    {
        if (fila[i] < 0)
        {
            contador_women += fila[i];
            indice_women++;
        }
        else
            contador_men += fila[i];
    }
    contador_women = (contador_women * -1) / indice_women;
    contador_men = contador_men / (fila.size() - indice_women);

    if (contador_men > contador_women)
        return "homens";
    else if (contador_women > contador_men)
        return "mulheres";
    else
        return "empate";
}

int main()
{
    // TESTES

    std::cout << "Existe ou nao\n"
              << existe({-1, -50, -99}, -1) << "\n";
    std::cout << existe({-1, -50, -99}, 10) << std::endl;

    std::cout << "Contagem\n"
              << contar({-1, -50, -1, -99}, -1) << "\n";
    std::cout << contar({-1, -50, -1, -99}, 10) << std::endl;

    std::cout << "Procurar\n"
              << procurar({-1, -50, -1 - 99}, -50) << "\n";
    std::cout << procurar({-1, -50, -1, -99}, 10) << std::endl;

    std::cout << "Procurar apartir\n"
              << procurar_valor({5, 3, -1, -50, -1, -99}, -1, 0) << "\n";
    std::cout << procurar_valor({5, 3, -1, -50, -1, -99}, -1, 3) << "\n";
    std::cout << procurar_valor({5, 3, -1, -50, -1, -99}, -1, 4) << std::endl;

    std::cout << "Menor Valor\n"
              << procurar_menor({5, 3, -1, -50, -1, -99}) << std::endl;

    std::cout << "Procurar menor posicao\n"
              << procurar_pos_menor({5, 3, -1, -50, -1, -99}) << std::endl;

    std::cout << "Procurar menor posicao apartir\n"
              << procurar_pos_menor_apartir({5, 3, -1, -50, -1, 10}, 3) << std::endl;

    std::cout << "Qual a posicao do homem mais calmo\n"
              << procurar_melhor_pos_se({5, 3, -1, -50, -1, -99}) << "\n";
    std::cout << procurar_melhor_pos_se({-1, -50, -1, -99}) << std::endl;

    std::cout << "Nivel medio de estress\n"
              << calcular_estress_medio({5, 3, -1, -50, -1, -99}) << std::endl;

    std::cout << "Mais homens ou mulheres?\n"
              << mais_homens_ou_mulheres({5, 3, -1, -50, -1, -99}) << "\n";
    std::cout << mais_homens_ou_mulheres({5, 3, 1, -50, -1, -99}) << "\n";
    std::cout << mais_homens_ou_mulheres({5, 3, 1, -50, -1, 99}) << std::endl;

    std::cout << "Qual metade mais estressada?\n"
              << qual_metade_eh_mais_estressada({5, 3, -1, -50, -1, -99}) << "\n";
    std::cout << qual_metade_eh_mais_estressada({50, 98, 2, -50, -1, -99}) << "\n";
    std::cout << qual_metade_eh_mais_estressada({-51, 99, 1, -50, -1, -99}) << std::endl;

    std::cout << "Quem sao mais estressados?\n"
              << quem_eh_mais_estressado({51, 99, 1, -50, -1, -99}) << std::endl;
    return 0;
}