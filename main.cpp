#include <iostream>
#include"menu.cpp"
using namespace std;


int main()
{
    if(menu()){
        cout<<"BYE"<<endl;
    }
    else{
        cout<<"SE VC ESTA AQUI EH PORQUE ALGO DEU ERRADO"<<endl;
        //n�o � atoa que se rompe um loop infinito onde n�o h� breaks, mas somente goto
    }
    return 0;
}
