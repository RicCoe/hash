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
        //não é atoa que se rompe um loop infinito onde não há breaks, mas somente goto
    }
    return 0;
}
