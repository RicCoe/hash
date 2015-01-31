#include<iostream>
#include<vector>
#include<cstdlib>
#include"hash.cpp"
bool menu(){
    while(true){
        inicio:
        cout<<"ESCOLHA A OPCAO DESEJADA:"<<endl;
        cout<<"##################################################"<<endl
            <<"#   1-LISTAR NOMES DOS COMPONENTES               #"<<endl
            <<"#   2-USAR METODO  DA  DIVISAOO                  #"<<endl
            <<"#   3-USAR METODO DA MULTIPLICACAO               #"<<endl
            <<"#   4-NOSSA PROPRIA FUNCAO HASH                  #"<<endl
            <<"#   5-SAIR DO PROGRAMA                           #"<<endl
            <<"##################################################"<<endl;
            int k;
            cin>>k;
            if(k==5){
                return true;
            }
            if(k==1){
                sayOurName();
                goto inicio;
            }
            cout<<"ESCOLHA A OPCAO DESEJADA:"<<endl;
            cout<<"##################################################"<<endl
                <<"#   1-TRATAR COLISOES                            #"<<endl
                <<"#   2- NAO TRATAR COLISOES                       #"<<endl
                <<"##################################################"<<endl;
            int z;
            cin>>z;
            int j;
            if(z==1){
                cout<<"ESCOLHA COMO TRATAR A COLISAO:"<<endl;
                cout<<"##################################################"<<endl
                    <<"#   1-PROXIMA POSICAO VAZIA                      #"<<endl
                    <<"#   2- RE-HASH                                   #"<<endl
                    <<"#   3- LISTA DE LISTA                            #"<<endl
                    <<"##################################################"<<endl;
                cin>>j;
            }
            bool t;
            if(z==1){
                t=true;
            }
            else{
                t=false;
            }
            cout<<"ESCREVA  O LIMITE INFERIOR"<<endl;
            int a;
            cin>>a;
            cout<<"ESCREVA  O LIMITE SUPERIOR"<<endl;
            int b;
            cin>>b;
            cout<<"ESCREVA  A QUANTIDADE DE VALORES"<<endl;
            int num;
            cin>>num;
            cout<<"ESCREVA O TAMANHO DA TABELA"<<endl;
            int tam;
            cin>>tam;
            vector<int> sorteados=aleatorio(a,b,num);
            vector< vector<int> > v1;
            vector<int> v2;
            float cons;
            if(k==3){
                cout<<"DIGITE A CONSTANTE DESEJADA"<<endl;
                cin>>cons;
            }
            if(z==1&&j==3){
                v1=criaTabela(tam,1);
                for(int i=0;i<sorteados.size();i++){
                    if(k==2){
                        gerenciaInsert(1,-1,v1,sorteados[i],t);
                    }
                    else{
                        if(k==3){
                            gerenciaInsert(2,cons,v1,sorteados[i],t);
                        }
                        else{
                            gerenciaInsert(3,-1,v1,sorteados[i],t);
                        }
                    }
                }
                imprimir(v1);
            }
            else{
                v2=criaTabela(tam);
                for(int i=0;i<sorteados.size();i++){
                    if(k==2){
                        gerenciaInsert(1,-1,v2,sorteados[i],t);
                    }
                    else{
                        if(k==3){
                            gerenciaInsert(2,cons,v2,sorteados[i],t);//knhnkjhjk
                        }
                        else{
                            gerenciaInsert(3,-1,v2,sorteados[i],t);
                        }
                    }
                }
                imprimir(v2);
            }
    }
    return false;
}








