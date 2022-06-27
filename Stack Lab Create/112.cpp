#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <stack>

struct Pos{
    int row;
    int col;
    Pos(int row, int col) : row(row), col(col){}
};

std::vector<Pos> get_neighbors(Pos p){
    int row = p.row, col = p.col;
    return {{row, col - 1}, {row - 1, col}, {row, col + 1}, {row + 1, col}};
}

void show_maze(std::vector<std::string> maze){
    
    for(int i = 0; i < (int) maze.size(); i++){
        std::cout << maze[i] << "\n";
    }
}

void get_input(int argc, char *argv[], int &rows, int &cols){

    if (argc != 3){
        std::cout << "Numero de argumentos invalidos\n";
        exit(1);
    }
    std::stringstream(argv[1]) >> rows;
    std::stringstream(argv[2]) >> cols;

}

void get_begin(int &row, int rows, int &col, int cols){

    row = 1 + (rand() % (rows - 2));
    col = 1 + (rand() % (cols - 2));
    
}

bool is_an_available_wall(std::vector<std::string> maze, Pos p){
    int nl = maze.size();
    int nc = maze[0].size();
    int available_neighbors{0};

    for (auto prox : get_neighbors(p)) {
        int row = prox.row, col = prox.col;
        if (maze[p.row][p.col] != '#') return false;
        if(!(row < 0 || row > nl - 1 || col < 0 || col > nc - 1) && maze[row][col] == '#') available_neighbors++;
    }  
    if(available_neighbors >= 3) return true;
    return false;
}

std::vector<Pos> get_possible_positions(std::vector<std::string> maze, Pos p){

    std::vector<Pos> vector_pos;
    std::vector<Pos> aux{get_neighbors(p)};


    for(int i = 0; i < (int) aux.size(); i++){

        if(is_an_available_wall(maze, aux[i])){
            vector_pos.push_back(aux[i]); 
        }
    }
    return vector_pos;
}

void creat_lab (std::vector<std::string> &maze, Pos p){

    std::stack<Pos> my_stack;
    int row = p.row, col = p.col;

    maze[row][col] = 'O';
    my_stack.push(p);

    while(!my_stack.empty()){
        std::vector<Pos> vizinhos = get_possible_positions(maze, my_stack.top());

        if(!vizinhos.empty()){

            std::random_shuffle(begin(vizinhos), end(vizinhos));
            maze[vizinhos.back().row][vizinhos.back().col] = 'O';
            //show_maze(maze); Show each move
            //getchar();
            my_stack.push(vizinhos.back());
            vizinhos.pop_back();

        } 
        else my_stack.pop();
    }
}

int main (int argc, char *argv[]){

    srand(time(NULL));
    int rows{0};
    int cols{0};
    int row_begin{0};
    int col_begin{0};

    get_input(argc, argv, rows, cols);
    std::vector<std::string> maze(rows, std::string(cols, '#'));
    get_begin(row_begin, rows, col_begin, cols);
    creat_lab(maze, Pos(row_begin, col_begin));
    show_maze(maze);
}