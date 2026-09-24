#include <iostream>
#include "funciones.h"
#include <string>

using namespace std;

int main(){
    short int a;
    cout<<"ingrese que caso quiere ver: ";
    cin>>a;
    while(a!=-1){
    switch (a){
        case 1:{
        a-=1;
        string texto="";
        cout<<"ingrese el texto que desea comprimir: ";
        cin>> texto;
        string comprimido=comprimir(texto);
        string descomprimido=descomprimir(comprimido);
        cout<<"texto original:"<<texto<<endl<<"texto comprimido: "<<comprimido<<endl<<"texto descomprimido: "<<descomprimido<<endl;
        break;
        }
        case 2:{
            a=-1;
            string texto = " ";
            cout << "ingrese el texto que desea comprimir: ";
            cin>>texto;
            string comprimido=comprimirdinamico(texto);
            string descomprimir=descomprimidinamico(comprimido);
            cout << "resultado compresion  LZ78 (indice)(caracter):\n" <<comprimido<<"resultado descompresion: "<<descomprimir<<endl;

            break;

        }
        case 3:{
            a=-1;
            string texto = " ";
            cout <<"ingrese el texto que desea comprimir: ";
            cin>>texto;
            int n=0;
            cout <<"Ingrese el valor de rotacion n (0 < n < 8): ";
            cin >>n;
            char x;
            cout <<"Ingrese la clave K (un caracter): ";
            cin >>x;
            string comprimido = comprimir(texto);
            cout <<"Texto comprimido: "<<comprimido<< endl;
            string encriptado = encriptarDatos(comprimido,n,x);
            cout <<"Texto encriptado: " << encriptado << endl;
            string desencriptado = desencriptarDatos(encriptado,n,x);
            cout <<"Datos desencriptados: "<<desencriptado<<endl;
            string descom=descomprimir(desencriptado);
            cout <<"texto des comprimido: "<<descom<<endl;
            break;
        }
}
        cout<<"ingrese que caso quiere ver ingrese 0 para terminar programa: ";
        cin>>a;
        if (a==0)
            break;
}
}

