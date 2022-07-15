#include <iostream>
#include <queue>

int main(){

    std::queue<char> lyrics;

    int ascii_lyric = 65;
    while(ascii_lyric != 81){
        lyrics.push(ascii_lyric);
        ascii_lyric++;
    }

    while(lyrics.size() != 1){

        int f_goals{0}, s_goals{0};
        std::cin >> f_goals >> s_goals;

        char var{};
        if(f_goals > s_goals){
            var = lyrics.front();
            lyrics.pop();
            lyrics.pop();
            lyrics.push(var);
        }
        else{
            lyrics.pop();
            var = lyrics.front();
            lyrics.pop();
            lyrics.push(var);
        }
    }

    std::cout << lyrics.front() << "\n";

    return 0;
}