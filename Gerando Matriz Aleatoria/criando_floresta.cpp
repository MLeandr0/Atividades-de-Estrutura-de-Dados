#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>

void show(std::vector<std::string> floresta)
{

    for (auto linha : floresta)
    {
        std::cout << linha << std::endl;
    }
}

void valores(int argc, char *argv[], int &nl, int &nc, int &porcentagem)
{

    if (argc != 4)
    {
        std::cout << "Numero de argumentos invalidos\n";
        exit(1);
    }
    std::stringstream(argv[1]) >> nl;
    std::stringstream(argv[2]) >> nc;
    std::stringstream(argv[3]) >> porcentagem;
}

void plantar_arvore(std::vector<std::string> &terreno, int &arvores, int nl, int nc)
{

    int i = rand() % nl;
    int j = rand() % nc;
    if (arvores == 0)
        return;
    if (terreno[i][j] != '.')
        return plantar_arvore(terreno, arvores, nl, nc);

    terreno[i][j] = '#';
    arvores -= 1;
    plantar_arvore(terreno, arvores, nl, nc);
}

int main(int argc, char *argv[])
{

    srand(time(NULL));
    int nl{0};
    int nc{0};
    int porcentagem{0};
    valores(argc, argv, nl, nc, porcentagem);
    std::vector<std::string> matriz(nl, std::string(nc, '.'));
    porcentagem = (porcentagem / 100.0) * (nl * nc);

    plantar_arvore(matriz, porcentagem, nl, nc);
    show(matriz);

    return 0;
}