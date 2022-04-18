#include <iostream>
#include <vector>

struct Pos
{
    int l;
    int c;
};

std::vector<Pos> get_vizinhos(Pos p)
{

    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

void show(std::vector<std::string> &matriz)
{

    for (std::string line : matriz)
    {
        std::cout << line << std::endl;
    }
}

bool achar_caminho(std::vector<std::string> &matriz, Pos comeco, Pos saida)
{

    if (saida.l == comeco.l && saida.c == comeco.c)
        return true;

    if (matriz[comeco.l][comeco.c] != '_')
        return false;

    matriz[comeco.l][comeco.c] = '.';
    for (auto vizinho : get_vizinhos(comeco))
    {
        bool caminho = achar_caminho(matriz, vizinho, saida);
        if (caminho)
            return true;
    }
    matriz[comeco.l][comeco.c] = '_';
    return false;
}

void remover_marcacao(std::vector<std::string> &matriz, Pos &inicio, Pos &fim)
{

    for (int l = 0; l < (int)matriz.size(); l++)
    {
        for (int c = 0; c < (int)matriz[l].size(); c++)
        {
            if (matriz[l][c] == 'I')
            {
                matriz[l][c] = '_';
                inicio = Pos{l, c};
            }
            if (matriz[l][c] == 'F')
            {
                matriz[l][c] = '_';
                fim = Pos{l, c};
            }
        }
    }
}

int main()
{

    int nl = 0, nc = 0;
    std::cin >> nl >> nc;
    std::vector<std::string> mat(nl, "");
    getchar();                            
    Pos inicio, fim;

    for (int i = 0; i < nl; i++)
    {
        getline(std::cin, mat[i]);
    }

    remover_marcacao(mat, inicio, fim);
    achar_caminho(mat, inicio, fim);
    show(mat);
    return 0;
}