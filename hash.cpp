#include <iostream>
#include<time.h>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<cmath>

using namespace std;


void imprimir(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    cout<<"@@@@@FIM@@@@@"<<endl;
}

vector<int>aleatorio(int a,int b,int num){ //retorna num números entre a e b
srand (time (NULL));
    if(num<(b-a)&&b>a){
        vector<int>v;
        for (int i = 0; i < num; i++){
            int y=rand() % (b - a + 1) + a;
            if(std::find(v.begin(),v.end(),y)==v.end()){
                v.push_back(y);
            }
        }
        return v;
    }
    vector<int>r;
    return r ;
}

vector<int>criaTabela(int tam){
    vector<int>v;
    for(int i=0;i<tam;i++){
        v.push_back(-1);
    }
    return v;
}

vector < vector<int> >criaTabela(int tam, int u){
    vector< vector<int> >vv;
    for(int i=0;i<tam;i++){
        vector<int>v;
        v.push_back(-1);
        vv.push_back(v);
    }
    return vv;
}

int hashingFunc1(int chave, int tam){//tam  é  o tamanho da tabela
    return chave % tam;
}
int reHash(int chave,int  num,vector<int>tabela, int pos){
    if(num<tabela.size()){
        int cont=1;
        int i=pos;
        do{
            if(tabela[i]==-1){
                return i;
            }
            else{
                i+=cont*(chave%num);
                cont++;
            }
        }
        while(i<tabela.size());
    }
    return -1;
}

bool insereFunc(vector<int>&tabela,int chave,bool t, int metodo,int pos){//quando estamos inserindo sem considerar listas de listas
    if(t){//sem tratamento de colisoes
        tabela[pos]=chave;
        return true;//deu certo
    }
    else {
        switch(metodo){
            case 1:{
                if(tabela[pos]==-1){
                    tabela[pos]=chave;
                    return true;
                }
                else{
                    int i=pos;
                    while(i<tabela.size()){
                        i++;
                        if(tabela[i]==-1){
                            tabela[i]=chave;
                            return true;
                        }
                    }
                    cout<<"A insercao da chave: "<<chave<<"falhou, seria inserida em:"<<pos<<endl;

                    return false;//deu  treta
                }
            }
            break;
            case 2:{//rehash
                int num=13;//numero primo ao acaso
                int y=reHash(chave,num,tabela,pos);
                if(y!=-1){
                    tabela[y]=chave;
                    return true;
                }
                return false;
            }
            break;
            default:{
                return false;
            }
        }
    }
}

bool insere (vector< vector<int> >&tabela, int chave,int pos){//para o caso vector de vector
    if(tabela[0][pos]==-1){
        tabela[0][pos]=chave;
        return true;
    }
    else{
        if(tabela[pos][0]==-1){
            tabela[pos][0]=chave;
        }
        else{
            tabela[pos].push_back(chave);
        }
    }
}

int hashingFunc2(int chave, int tam, float cons){
    return (int)(tam*(cons*chave-(int)(cons*chave)));
}
int nossoHash(int chave, int tam){
    return ((int)(pow(((int)(pow(chave*1.6180339887,2)))%tam,2)*1.6180339887))%tam;
}


bool gerenciaInsert(int op, float cons, vector<int>&tabela, int chave,bool t){
    int pos;
    switch(op){
        case 1:{
            pos=hashingFunc1(chave,tabela.size());
        }
        break;
        case 2:{
            pos=hashingFunc2(chave,tabela.size(),cons);
        }
        break;
        case 3:{
            pos=nossoHash(chave,tabela.size());
        }
        break;
        default:{
            return false;
        }
    }
    bool y=insereFunc(tabela,chave,t,op,pos);
    return y;
}

bool gerenciaInsert(int op, float cons, vector< vector<int> >&tabela, int chave,bool t){
    int pos=-1;
    switch(op){
        case 1:{
            pos=hashingFunc1(chave,tabela.size());//metodo da divisao
        }
        break;
        case 2:{
            pos=hashingFunc2(chave,tabela.size(),cons);//metodo da multiplicacao
        }
        break;
        case 3:{
            pos=nossoHash(chave,tabela.size());
        }
        break;
        default:{
            return false;
        }
    }
    if(pos!=-1){
        bool y=insere(tabela,chave,pos);
        return y;
    }
    return false;
}

void sayOurName(){
    cout<<"Hello Darkness my old Friend...";
}

void imprimir(vector< vector<int> >v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<",";
        }
        cout<<endl;
    }
    cout<<"@@@@@FIM@@@@@"<<endl;
}










