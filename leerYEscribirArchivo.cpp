/**
 * @file leerYEscribirArchivo.cpp
 *
 * Definicion de la clase "Archivo"
 * 
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 05/09/2021
 */

#include"leerYEscribirArchivo.h"

int strToInt(string strNumero, int cantDigitos)
{
    // Para las unidades, decenas, centenas, etc
    int cifra = 1;
    int numero = 0;

    // Bucle que convierte la cadena en un entero
    while(cantDigitos > 0)  {
        // Identifica la cifra
        switch(strNumero[cantDigitos - 1])  {
            case '0':
                numero += 0;
                break;

            case '1':
                numero += 1 * cifra;
                break;

            case '2':
                numero += 2 * cifra;
                break;

            case '3':
                numero += 3 * cifra;
                break;

            case '4':
                numero += 4 * cifra;
                break;

            case '5':
                numero += 5 * cifra;
                break;

            case '6':
                numero += 6 * cifra;
                break;

            case '7':
                numero += 7 * cifra;
                break;

            case '8':
                numero += 8 * cifra;
                break;

            case '9':
                numero += 9 * cifra;
                break;

            case '-':
                numero *= -1;
                break;
        }
        cifra *= 10;  // Para la siguiente cifra
        cantDigitos--;
    }

    return numero;
}

Archivo::Archivo(string nombreArch)
{
    // Abre el archivo
    archivo.open(nombreArch, ios::in);

    // Comprueba si se abrio correctamente el archivo
    if(!archivo.is_open())  {
        cout << "No fue posible abrir el archivo" << endl;
        exit(1);
    }
    
    // Inicializa las demas variables de clase
    cantNum = 0;
    cadenaNumeros = "";
    ptrNumeros = NULL;
}

void Archivo::contarNumerosYCrearCadenaNumeros()
{
    string tmp;
    // Recorre el archivo, cuenta la cantidad de lineas que hay en el archivo y extrae los numeros en formato "str"
    while(!archivo.eof())  {
        while(getline(archivo, tmp))  {
            // Ira concantenando los numeros y los separara con una "x"
            cadenaNumeros += tmp + 'x';
            cantNum++;
        }
    }

    // Se posiciona al inicio del archivo
    archivo.clear();
    archivo.seekg(0, archivo.beg);

    // Cierra el archivo
    archivo.close();
}

void Archivo::extraerNumeros()
{
    // Declaracion de indices que reccoreran la cadena y de dos contadores
    int l, r, cont, digitos;
    l = r = cont = digitos = 0;
    // Cadena que contendra cada numero en formato "str" para convertirlo a "int"
    string numero = "";
    // Crea el arreglo que contendra los numeros
    int *numeros = new int [cantNum];

    // Bucle que se repetira hasta que el indice "r" llegue al indice final de la cadena
    while(r < cadenaNumeros.length())  {
        // Si no se ha llegado al final del numero
        if(cadenaNumeros[r] != 'x')  {
            r++;
        }
        // Si ya se llego al final del numero
        else  {
            // Bucle que copia el numero en formato "str"
            while(l < r)  {
                numero += cadenaNumeros[l];
                l++;
                digitos++;
            }
            // Pasa al indice donde comienza un nuevo numero
            r++;
            l++;
            // Convierte el numero a entero y lo almacena en el arreglo
            *(numeros + cont) = strToInt(numero, digitos);
            // Borra los valores de "numero" y "digitos" para un nuevo numero
            numero = "";
            digitos = 0;
            cont++;
        }
    }

    ptrNumeros = numeros;
}

int Archivo::getCantNum()
{
    return cantNum;
}

int* Archivo::getPtrNumeros()
{
    return ptrNumeros;
}

void Archivo::escribirArrDocTxt(string nombre)  // PEDIR NOMBRE DE ARCHIVO DE SALIDA SIN EXTENSION
{
    // Archivo de texto con la salida
    ofstream salida;
    // Crea o reemplaza el archivo con identificador "nombre"
    salida.open(nombre, ios::out);

    // Comprueba si se abrio correctamente el archivo
    if(!salida.is_open())  {
        cout << "No fue posible abrir el archivo" << endl;
        exit(1);
    }

    // Bucle que recorre el arreglo al que apunta "ptrNumeros"
    for(int i = 0; i < cantNum; i++)  {
        // Escribe cada elemento del arreglo en el archivo "salida"
        salida << *(ptrNumeros + i) << endl;
    }

    // Cierra el archivo
    archivo.close();
}