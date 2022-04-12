#include <iostream>
#include <vector>

void show(std::vector<std::string> mat)
{
    for (int i = 0; i < (int)mat.size(); i++)
    {
        std::cout << mat[i] << "\n";
    }
    //getchar(); testando o que vimos em sala
}

void tocar_fogo(std::vector<std::string> &mat, int linha, int coluna)
{
    int nl = mat.size();
    int nc = mat[0].size();

    if (linha < 0 || linha >= nl || coluna < 0 || coluna >= nc)
        return;
    if (mat[linha][coluna] == '.' || mat[linha][coluna] == 'O')
        return;

    mat[linha][coluna] = 'O';
    show(mat); //testando o que vimos em sala

    tocar_fogo(mat, linha - 1, coluna);
    tocar_fogo(mat, linha, coluna - 1);
    tocar_fogo(mat, linha + 1, coluna);
    tocar_fogo(mat, linha, coluna + 1);

    /*Testando as coisas que vimos em sala
    mat[linha][coluna] = '+';
    show(mat);
    */
    
}

int main()
{
    //OBS: ainda to fazendo uns testes, porém ta funcionando
    int nl{}, nc{}, lfire{}, cfire{};
    scanf("%d %d %d %d\n", &nl, &nc, &lfire, &cfire);
    std::vector<std::string> mat;

    for (int i = 0; i < nl; i++)
    {
        std::string line;
        std::cin >> line;
        mat.push_back(line);
    }

    tocar_fogo(mat, lfire, cfire);
    //show(mat);

    return 0;
}