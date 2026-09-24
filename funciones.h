#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>

using namespace std;

string comprimir(const string& texto);
string descomprimir(const string& comprimido);
string comprimirdinamico(const string& texto);
string descomprimidinamico(const string& comprimido);
string encriptarDatos(const string& texto, int n, char x);
string desencriptarDatos(const string& textoEncriptado,int n,char x);

#endif // FUNCIONES_H
