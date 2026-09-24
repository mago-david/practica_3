#include "funciones.h"
#include <iostream>
#include <string>

using namespace std;

string comprimir(const string& texto){
    string resultado="";
    int n=texto.length();
    for (int i=0;i<n;i++){
        int conteo=1;
        while (i+1<n && texto[i]==texto[i + 1]) {
            conteo++;
            i++;
        }
        resultado +=to_string(conteo)+texto[i];//to_estring funcion pre determinada de <string> convierte numeros en char
    }
    return resultado;
}
string descomprimir(const string& comprimido) {
    string resultado ="";
    int n=comprimido.length();
    for (int i=0;i<n;i++) {
        string Conteo_numero="";
        while (i<n && isdigit(comprimido[i])) {//isdigit verifica que el caracter sea un numero (bool)
            Conteo_numero+=comprimido[i];
            i++;
        }
        int conteo=stoi(Conteo_numero);//convierte numeros de tipo char a tipo int
        char c=comprimido[i];
        resultado.append(conteo, c);
    }
    return resultado;
}
string comprimirdinamico(const string& texto) {
    int inicio=100;
    int *ptrpref = new int[inicio];
    char *ptrcar=new char[inicio];
    int tamaño=0;
    int n=texto.length();
    int i=0;
    string resultadoComprimido="";
    while(i < n) {
        int actual=0;
        int j=i;
        while (j < n) {
            char c=texto[j];
            int siguiente=-1;
            for(int x=1;x<=tamaño;x++) {
                if(ptrpref[x]==actual && ptrcar[x]==c) {
                    siguiente=x;
                    break;
                }
            }
            if(siguiente !=-1) {
                actual=siguiente;
                j++;
            } else {
                break;
            }
        }
        char final;
        if(j<n) {
            final=texto[j];
        } else {
            final ='\0';
        }
        if(j < n) {
            resultadoComprimido +="["+to_string(actual)+"---"+final + "]\n";
        }
        tamaño++;
        ptrpref[tamaño]=actual;
        ptrcar[tamaño]=final;
        i=j+1;
    }
    delete[] ptrpref;
    delete[] ptrcar;
    return resultadoComprimido;
}
string descomprimidinamico(const string& comprimido) {
    int capPares = 100;
    int *indices = new int[capPares];
    char *caracteres = new char[capPares];
    int totalPares = 0;
    int n = comprimido.length();
    int i = 0;
    while (i < n && totalPares < capPares) {
        if (comprimido[i] == '[') {
            i++;
            string sIndice = "";
            while (i < n && comprimido[i] != '-') {
                sIndice += comprimido[i];
                i++;
            }
            while (i<n && comprimido[i]== '-') {
                i++;
            }
            char c=comprimido[i];
            i++;
            indices[totalPares]=stoi(sIndice);
            caracteres[totalPares]=c;
            totalPares++;
        }
        i++;
    }
    int capDic=100;
    string *ptrdic=new string[capDic];
    int tamDic=0;
    ptrdic[0]="";
    string resultadoDescomprimido="";
    for (int k=0;k<totalPares && tamDic<capDic- 1;k++) {
        int indice=indices[k];
        char c=caracteres[k];
        string original=ptrdic[indice];
        string nuevo=original+c;
        resultadoDescomprimido+=nuevo;
        tamDic++;
        ptrdic[tamDic]=nuevo;
    }
    delete[] indices;
    delete[] caracteres;
    delete[] ptrdic;
    return resultadoDescomprimido;
}
string encriptarDatos(const string& texto, int n, char x){
    string resultado=texto;
    int len=resultado.length();
    for (int i=0;i<len;i++) {
        unsigned char byteActual=(unsigned char)resultado[i];
        unsigned char rotado=(byteActual << n) | (byteActual>>(8 - n));
        unsigned char encriptado=rotado^(unsigned char)x;
        resultado[i]=(char)encriptado;
    }
    return resultado;
}
string desencriptarDatos(const string& textoEncriptado,int n,char x) {
    string resultado=textoEncriptado;
    int len=resultado.length();
    for (int i=0;i<len;i++){
        unsigned char byteActual=(unsigned char)resultado[i];
        unsigned char sinXor=byteActual^(unsigned char)x;
        unsigned char desencriptado=(sinXor>>n) | (sinXor<<(8-n));
        resultado[i]=(char)desencriptado;
    }
    return resultado;
}
