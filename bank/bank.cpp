#include <iostream>
#include <vector>
#include <sstream>
#include <list>

using namespace std;

struct Client{
    string name;
    int docs;
    int patience;
    Client(string _name, int _actions, int _patience){
        this->name = _name;
        this->docs = _actions;
        this->patience = _patience;
    }
    string str(){
        return name + ":" + to_string(docs) + ":" + to_string(patience);
    }
};

struct Banco{
    vector<Client*> teller; //caixas
    list<Client*> queue_in; //fila de entrada
    list<Client*> queue_out;//fila de saida
    int received {0};       //documentos processados
    int lost {0};           //documentos perdidos
    int tics {0};           //quantidade de tempo que passou


    //iniciliza so caixas
    Banco(int teller_size) {
        teller.resize(teller_size);
    }

    //insere cliente na fila de entrada
    void insert(Client * client) { 
        queue_in.push_back(client);
    }

    //esta vazio se não tem ninguém no banco
    bool empty() { 
        if(!teller.empty() && !queue_in.empty()) return false;
        return true;
    }

    //roda o algoritmo de passagem de tempo
    void tic() { 
        while(!queue_out.empty()) queue_out.pop_front();

        for(int i = 0; i < teller.size(); i++){

            if(teller[i]){
                if(teller[i]->docs != 0) {
                    teller[i]->docs--;
                    this->received++;
                
                }
                else {
                    queue_out.push_back(teller[i]);
                    teller[i] = nullptr;
                }
            }
            else{
                if(!queue_in.empty()){
                    teller[i]= queue_in.front();
                    queue_in.pop_front();
                }
            
            }
        }

        list<Client*>::iterator itt = queue_in.begin();
        while(itt != queue_in.end()){
            if((*itt)->patience > 0) { 
                (*itt)->patience--;
                itt++;
            }
            else{
                queue_out.push_back(*itt);
                list<Client*>::iterator aux = itt;
                lost += (*itt)->docs;
                itt++;
                queue_in.erase(aux);
            }
        }

        tics++;
    }

    //mostra o banco
    void show_all(){
        for(auto client : teller){
            cout << "[" << (client == nullptr ? "" : client->str()) << "]";
        }
        cout << "\nin :{ ";
        for(auto client : queue_in)
            cout << client->str() << " ";
        cout << "}\nout:{ ";
        for(auto client : queue_out)
            cout << client->str() << " ";
        cout << "}\n";
    }
};

int main(){
    Banco banco(3);

    while(true){
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << "\n";
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        }
        if(cmd == "show"){
            banco.show_all();
        }else if(cmd == "in"){
            string name;
            int docs, patience;
            ss >> name >> docs >> patience;
            banco.insert(new Client(name, docs, patience));
        }else if(cmd == "init"){
            int size;
            ss >> size;
            banco = Banco(size);
        }else if(cmd == "tic"){
            banco.tic();
        }else if(cmd == "finish"){
            while(!banco.empty()){
                banco.tic();
            }
            cout << "received: " << banco.received << endl;
            cout << "lost: " << banco.lost - 1 << endl;
            cout << "tics: " << banco.tics << endl;
        }else{
            cout << "fail: command not found\n";
        }
    }
}